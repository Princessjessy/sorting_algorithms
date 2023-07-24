#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, temp, check = 0;

	if (array)
	{
		while (i + 1 < size)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				check = 1;
			}
			i++;
		}
		if (check == 1)
			bubble_sort(array, size);
	}
}
