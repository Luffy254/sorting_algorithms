#include "sort.h"

/**
 * shell_sort - uses the shell sort algorithm to sort array
 * @array: array sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int interval = 1, i, j;
	int temp;

	if (array == NULL || !size || size < 2)
		return;

	while (interval < (int)size / 3)
		interval = interval * 3 + 1;
	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			temp = array[i];
			j = i;
			while (j > (interval - 1) && array[j - interval] >= temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		interval = interval / 3;
		print_array(array, size);
	}
}
