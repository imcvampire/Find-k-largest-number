#include "stdio.h"
#include "stdlib.h"

#define n0 100000000
#define k 600000

int *f;
int *result;

void add(int new_number) {
	static int id = 0;
	result[id] = new_number;
	++id;
}

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

        // Swap with the lowest valud in the triplet
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
	int i, j, temp;
	f = (int *) malloc((n0 - k) * sizeof(int));
	result = (int *) malloc(k * sizeof(int));

	if (f == NULL)
	{
		return -1;
	}

	for (i = 0; i < n0 - k; ++i)
	{
		f[i] = rand();
	}

	// Build the heap of (n0 - k) numbers. Cost: O(n0 - k)
	heapify(f, n0 - k);

    /**
     * For each of the rest k number. If its value is lower than min heap, it will be
     * added to the result array (because it's lower than n0 - k other number).
     * Otherwise, it would replace the min heap value. The heap will be heapify 
     * and the min value will be pushed to the result.
     * 
     * The complexity is log(n0 - 1) + log(n0 - 2) + ... + log(n0 - k)
     * */

	add(f[0]);

	for (i = 1; i < k; ++i)
	{
        temp = rand();
        if (temp >= f[0])
        {
            add(f[0]);
            f[0] = temp;
            shiftdown(f, 0, n0 - k);
        }
        else
        {
            add(temp);
        }
	}

    // The result will contains min values

	free(f);
	free(result);

	return 0;
}
