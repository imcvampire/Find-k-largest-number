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
	f = (int *) malloc(k * sizeof(int));

	if (f == NULL) {
		return -1;
	}

	// generate k number
	for (i = 0; i < k; ++i)
	{
		f[i] = rand();
	}

	// k
	heapify(f, k);

	// nlogk
	for (i = 0; i < n0; ++i)
	{
		int temp = rand();

		if (temp > f[0])
		{
			f[0] = temp;
			shiftdown(f, 0, k);
		}
	}

	free(f);

	return 0;
}