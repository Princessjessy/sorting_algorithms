#include "sort.h"
/**
 * max_int - find the maximum integer in an array
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: The maximum integer
 */
int max_int(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * createArray - creates an array with malloc
 * @size: size of the array
 *
 * Return: a pointer to the array
 */
int *createArray(size_t size)
{
	int *ptr = malloc(sizeof(int) * size);

	return (ptr);
}

/**
 * counting_sort -  sorts an array of integers in ascending order using the
 *		Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, k;
	int *count, *output_array, j;

	if (size != 1 && array)
	{
		k = max_int(array, size);
		count = createArray(k + 1);
		output_array = createArray(size);

		if (!k || !count)
			exit(8);
		/* initialises the count array to 0 */
		for (i = 0; i <= k; i++)
			count[i] = 0;

		/* storing the count of elements having distinct key values */
		for (i = 0; i < size; i++)
			++count[array[i]];

		/* update the count array to actual position of the element */
		for (i = 1; i <= k; i++)
			count[i] += count[i - 1];
		print_array(count, k + 1);

		/* fill output array in sorted order */
		for (j = size - 1; j >= 0; j--)
		{
			output_array[count[array[j]] - 1] = array[j];
			/* decrement the position value*/
			--count[array[j]];
		}

		/* copy output array back to input array */
		for (i = 0; i < size; i++)
			array[i] = output_array[i];

		free(count);
		free(output_array);
	}
}
