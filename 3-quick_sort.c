#include <stdio.h>
#include "sort.h"
/**
  * swap - swap two integers and prints the array
  *
  * @a: pointer to first integer to swap
  * @b: pointer to second integer to swap
  */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
  * partition - sort array using lomuto partition scheme
  *
  * @array: array soted
  * @low: first index of partition
  * @high: last index of partition
  * @size: size of the array
  *
  * Return: new pivot
  */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, a;

	pos = array[high];

	for (a = low, int b = low; b <= high; b++)
	{
		if (array[b] <= pos && array[b] < array[a])
		{
			swap(&array[b], &array[a]);
			print_array(array, size);
			a++;
		}

		if (array[b] <= pos)
			a++;

	}
	return (a - 1);
}

/**
  * quicksort - performs the recursion of Quick Sort function
  *
  * @array: array to be sorted
  * @low: first index of partition
  * @high:last index of partition
  * @size: size of the array
  */

void quicksort(int *array, int low, int high, size_t size)
{
	int postn;

	if (low < high)
	{
		postn = partition(array, low, high, size);
		quicksort(array, low, postn - 1, size);
		quicksort(array, postn + 1, high, size);
	}
}
/**
  * quick_sort - uses using quick sort function to sort array
  *
  * @array: array sorted
  * @size: size of the array
  */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
