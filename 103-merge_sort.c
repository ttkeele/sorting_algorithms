#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges to the array
 * @array: the array to sort
 * @li: index to start left array
 * @ri: index to end right array
 * @mid: index to stop left array
 */

void merge(int *array, int li, int mid, int ri)
{
	int i, j, k;
	int n1 = mid - li + 1;
	int n2 = ri - mid;
	int left[1024], right[1024];

	printf("Merging...\n");
	for (i = 0; i < n1; i++)
		left[i] = array[li + i];
	printf("[left]: ");
	print_array(left, n1);
	for (j = 0; j < n2; j++)
	{
		right[j] = array[mid + 1 + j];
	}
	printf("[right]: ");
	print_array(right, n2);
	for (i = 0, j = 0, k = li; i < n1 && j < n2; k++)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
	}
	for (; i < n1; i++, k++)
		array[k] = left[i];
	for (; j < n2; j++, k++)
		array[k] = right[j];
	printf("[Done]: ");
	print_array(&array[li], n1 + n2);
}

/**
 * mergeSort - performs a merge sort on an array
 * @array: the array to sort
 * @li: index to start left array
 * @ri: index to start right array
 */

void mergeSort(int *array, int li, int ri)
{
	int mid = (ri + li - 1) / 2;

	if (li < ri)
	{
		mergeSort(array, li, mid);
		mergeSort(array, mid + 1, ri);

		merge(array, li, mid, ri);
	}
}

/**
 * merge_sort - performs a merge sort on an array
 * @array: the array to sort
 * @size: number of elements in the array
 */

void merge_sort(int *array, size_t size)
{
        if (size > 1)
	        mergeSort(array, 0, size - 1);
}
