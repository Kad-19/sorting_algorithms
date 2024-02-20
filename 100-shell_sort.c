#include "sort.h"

/**
* shell_sort - function sorts an array of integers
* @array: the array of integers to be sorted
* @size: size of the array
*
*/
void shell_sort(int *array, size_t size)
{
	size_t dif = 0, j, i;
	int gp;

	if (size < 2)
		return;

	while ((dif = dif * 3 + 1) < size)
		;

	dif = (dif - 1) / 3;

	for (; dif > 0; dif = (dif - 1) / 3)
	{
		for (i = dif; i < size; i++)
		{
			gp = array[i];
			for (j = i; j >= dif && gp <= array[j - dif]; j -= dif)
				array[j] = array[j - dif];
			array[j] = gp;
		}
		print_array(array, size);
	}
}
