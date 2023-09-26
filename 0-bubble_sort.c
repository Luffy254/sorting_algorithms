#include "sort.h"

/**
 * bubble_sort - sorts array of integers in ascending order using
 *               the Bubble sort algorithm
 * @array: array to be sorted
 * @size: Number of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t j;
	int tmp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	swapped = 1;

	while (swapped)
	{
		swapped = 0;

		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
