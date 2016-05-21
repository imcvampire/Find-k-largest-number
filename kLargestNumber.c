#include "stdio.h"
#include "stdlib.h"

const int n = 1000000000;
const int k = 600000;


int f[k];

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void quicksort(int a[], int left, int right)
{
	int i = left, j = right;
	int pivot = a[(left + right) / 2];
	do
	{
		while (a[i] < pivot && i < right) i++;
		while (a[j] > pivot && j > left) j--;
		if (i <= j)
    	{
      		swap(a[i], a[j]);
      		i++; 
      		j--;
    	}
  	} while (i <= j);
   
  	if (left < j) quicksort(a, left, j);
  	if (i < right) quicksort(a, i, right);
}

int midpoint(int imin, int imax) 
{
	return (imin + imax) / 2;
}

int binarysearch(int a[], int key, int imin, int imax)
{
	if (imin > imax)
		return -1;

	if (imin == imax)
		if (a[imin] < key && (imid == 0 || key <= a[imin + 1]))
			return imin;
		else
			return -1;

	int imid = midpoint(imin, imax);

	if (key > a[imid])
		return binarysearch(a, key, imid + 1, imax);
	else
		return binarysearch(a, key, imin, imid);
}

int main(int argc, char const *argv[])
{
	int i, j;

	// generate k number
	for (i = 0; i < k; ++i)
	{
		f[i] = rand();
	}

	// // insertion sort
	// for (j = 1; j < k; ++j)
	// {
	// 	int tempsort = f[j];
	// 	i = j - 1;

	// 	while (i > 0 && f[i] > tempsort) 
	// 	{
	// 		f[i + 1] = f[i];
	// 		i -= 1;
	// 	}
	// 	f[i + 1] = tempsort;
	// }

	// quick sort
	// quicksort(f, 0, k - 1);

	// // compare with n-k number
	// for (i = k; i < n; ++i)
	// {
	// 	int temp = rand();
	// 	// printf("%d\n", temp);

	// 	if (temp > f[k - 1])
	// 	{
	// 		// binary search
	// 		int key = binarysearch(f, temp, 0, k - 1);

	// 		// insert to array
	// 		int j;
	// 		for (j = k - 1; j < key; --j)
	// 		{
	// 			f[j] = f[j - 1];
	// 		}
	// 		f[key] = temp;
	// 	}
	// }

	// // test sort
	// for (i = 0; i < k; ++i)
	// {
	// 	printf("%d\n", f[i]);
	// }

	
	return 0;
}