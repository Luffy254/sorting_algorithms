#include "sort.h"

/**
 * shell_sort - uses shell sort algorithm to sort array
 * @array: array sorted
 * @size: size of array
 *
 */
void shell_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	size_t gap = 1;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (size_t i = gap; i < size; i++)
		{
			int tmp = array[i];
			size_t j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = tmp
		}

		print_array(array, size);

		gap /= 3;
	}
}
