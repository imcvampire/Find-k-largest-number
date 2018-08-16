#include "stdio.h"
#include "stdlib.h"

#define n0 100000000
#define k 600000

int *f;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int leftchildnode(int n)
{
	return 2 * n + 1;
}

int rightchildnode(int n)
{
	return 2 * n + 2;
}

int parentnode(int n)
{
	return (n - 1) / 2;
}

void shiftdown(int a[], int start, int count)
{
	int i = start;

	int imax = parentnode(count + 1);
	while (i < imax)
	{
		int currentnodeindex = i;
		int leftnodeindex = leftchildnode(i);
		int rightnodeindex = rightchildnode(i);

		if (leftnodeindex < count && a[leftnodeindex] < a[i])
		{
			i = leftnodeindex;
		}

		if (rightnodeindex < count && a[rightnodeindex] < a[i])
		{
			i = rightnodeindex;
		}

		if (i != currentnodeindex)
		{
			swap(&a[currentnodeindex], &a[i]);
		}
		else
			break;
	}
}

void heapify(int a[], int count)
{
	int i;

	for (i = parentnode(count - 1); i > -1; --i)
	{
		shiftdown(a, i, count);
	}
}

void heapsort(int a[], int count)
{
	int end = count - 1;

	while (end > 0)
	{
		swap(&a[0], &a[end]);
		shiftdown(a, 0, end);
		--end;
	}
}

int main(int argc, char const *argv[])
{
	int i, j;
	f = (int *) malloc(n0 * sizeof(int));

	if (f == NULL)
	{
		return -1;
	}

	// generate (n0 - k) number
	for (i = 0; i < n0 - k; ++i)
	{
		f[i] = rand();
	}

	// n0
	heapify(f, n0);

	// log(n0 - 1) + log(n0 - 2) + ... + log(n0 - k)
	for (i = 1; i < k; ++i)
	{
		f[0] = f[n0 - i - 1];
		shiftdown(f, 0, n0 - i);
	}

	free(f);

	return 0;
}
