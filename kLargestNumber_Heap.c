#include "stdio.h"
#include "stdlib.h"

#define n0 100000000
#define k 600000

int *f;
int *result;

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

		// Swap with the lowest value in the triplet
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
	int i, temp;
	f = (int *) malloc(k * sizeof(int));

	if (f == NULL) {
		return -1;
	}

	// generate k numbers
	for (i = 0; i < k; ++i)
	{
		f[i] = rand();
	}

	// k min heap
	heapify(f, k);

	// (n0 - k)logk
	for (i = 0; i < n0 - k; ++i)
	{
		// Generate n0 - k numbers
		temp = rand();

		/**
		 * If the new int value is greater than the lowest value of the
		 * array, then it will be replaced. The heap will be heapified
		 * again. The complexity is (n0 - k)logk.
		 * */ 
		if (temp > f[0])
		{
			f[0] = temp;
			shiftdown(f, 0, k);
		}
	}

	/**
	 * The heap will contains max values. Notice: the first value in
	 * the heap will be the smallest value
	 * */

	result = f;

	free(result);

	return 0;
}
