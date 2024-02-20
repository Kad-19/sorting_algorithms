#include "sort.h"

/**
 * swap - swaps 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @a: address of first value
 * @b: address of second value
 *
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_p - partitions the array
 * @array: the integer array
 * @size: the size of the array
 * @bottom: the low index of the sort range
 * @top: the high index of the sort range
 *
 * Return: void
 */
size_t lomuto_p(int *array, size_t size, ssize_t bottom, ssize_t top)
{
	int i, j, pivot = array[top];

	for (i = j = bottom; j < top; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[top]);

	return (i);
}

/**
 * qsort - quicksorts using Lomuto partitioning scheme
 * @array: the integer array
 * @size: the size of the array
 * @bottom: the bottom index of the sort range
 * @top: the top index of the sort range
 *
 */
void qsort(int *array, size_t size, ssize_t bottom, ssize_t top)
{
	if (bottom < top)
	{
		size_t k = lomuto_p(array, size, bottom, top);

		qsort(array, size, bottom, k - 1);
		qsort(array, size, k + 1, top);
	}
}

/**
 * quick_sort - envokes sorting
 * @size: size of the array
 * @array: the integer array to sort
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	qsort(array, size, 0, size - 1);
}
