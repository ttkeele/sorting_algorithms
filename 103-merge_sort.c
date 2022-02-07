#include "sort.h"
/**
 * sorts an array of integers in ascending order using the Merge sort algorithm
 @array: The array to be sorted
 * @size: Number of elements in array
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	int *out_arr;
	out_arr = malloc(sizeof(int) * (size + 1));
	// base case: 0 or 1 node
	if (*array == NULL || out_arr->next == NULL) {
		return;
	}

	// split head into `a` and `b` sublists*
	struct Node* a = *array, *b = NULL;
	split(*array, &a, &b);

	// recursively sort the sublists
	merge_sort(array, &a);
	merge_sort(array, &b);

	// merge the two sorted lists
	*array = merge(a, b);
}
