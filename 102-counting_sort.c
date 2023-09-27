#include "sort.h"
/**
 * counting_sort - uses counting sort algorithm to sort array
 * @array: array to be sorted
 * @size: size of arrays
 */

void counting_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int max_num = array[0];

	for (size_t k = 0; k < size; k++)
	{
		if (array[k] > max_num)
			max_num = array[k];
	}

	int *count = malloc((max_num + 1) * sizeof(int));
	int *sorted_array = malloc(size * sizeof(int));

	if (count == NULL || sorted_array == NULL)
	{
		free(count);
		free(sorted_array);
		return;
	}

	for (int i = 0; i <= max_num; i++)
		count[i] = 0;
	for (size_t k = 0; k < size; k++)
		count[array[k]]++;
	for (int i = 1; i <= max_num; i++)
		count[i] += count[i - 1];

	print_array(count, max_num + 1);

	for (size_t k = 0; k < size; k++)
	{
		sorted_array[count[array[k]] - 1] = array[k];
		count[array[k]]--;
	}

	for (size_t k = 0; k < size; k++)
		array[k] = sorted_array[k];
	free(count);
	free(sorted_array);
}
