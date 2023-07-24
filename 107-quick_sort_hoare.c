#include "sort.h"

/**
 * hoare_partition - partition the input arr into two
 * sub-arrays around a pivot element
 *
 * @arr: array
 * @low: start index
 * @high: end index
 * @size: size of array
 *
 * Return: final position of the pivot
 */
int hoare_partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], i = --low, j = ++high, temp;

	while (1)
	{
		i++;
		while (arr[i] < pivot)
			i++;
		j--;
		while (arr[j] > pivot)
			j--;
		if (i > j)
			return (j);

		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		if (i != j)
			print_array(arr, size);
	}
}

/**
 * quick_sort_h - sorts the input arr
 *
 * @array: array
 * @low: start index
 * @high: end index
 * @size: size of array
 */
void quick_sort_h(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = hoare_partition(array, low, high, size);
		quick_sort_h(array, low, partition_index, size);
		quick_sort_h(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	int low = 0, high = size - 1;

	quick_sort_h(array, low, high, size);
}
