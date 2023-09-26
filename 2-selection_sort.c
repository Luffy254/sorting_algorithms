#include "sort.h"

/**
  * selection_sort - sort using selection sort algorithm
  *
  * @array: array to be sorted
  * @size: number of elements in array
  */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, min_index;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				if (array[j] < array[min_index])
					min_index = j;
			}
		}

		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
