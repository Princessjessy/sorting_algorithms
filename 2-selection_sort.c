#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: pointer to the array
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	int min, temp, check;
	size_t i, j, k;

	for (i = 0; i < size; i++)
	{
		check = 0;
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				k = j;
				check = 1;
			}
		}
		if (check)
		{
			temp = array[i];
			array[i] = min;
			array[k] = temp;
			print_array(array, size);
		}
	}
}
