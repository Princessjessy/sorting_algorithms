#include "sort.h"

/**
 * swap - swaps two array elements
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - implements the Lomuto partition scheme
 * @array: pointer to the array
 * @low: starting index of the sub-array
 * @high: ending index of the sub-array
 * @size: size of the array
 *
 * Return: index of the new pivot element
 */
int partition(int *array, int low, int high, int size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (array[j] < pivot && i != j)
			{
				/* To avoid swapping & printing the same index */
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high) /* To avoid swapping & printing the same index */
		print_array(array, size);
	return (i + 1);
}

/**
 * sort - main sorting function
 * @array: pointer to the array
 * @low: starting index of the sub-array
 * @high: ending index of the sub-array
 * @size: size of the array
 */
void sort(int *array, int low, int high, int size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		sort(array, low, pi - 1, size);
		sort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
