#include "sort.h"

/**
 * printArray - Prints an array
 * @array: array
 * @array_size: size of an array
 * @desc: description tag
 */
void printArray(int *array, int array_size, char *desc)
{
	char *separator = NULL;
	int i;

	printf("[%s]: ", desc);
	for (i = 0; i < array_size; i++)
	{
		if (separator)
			printf("%s", separator);
		printf("%d", array[i]);
		separator = ", ";
	}
	printf("\n");
}
/**
 * merge - merges the two sorted sub-arrays into a single sorted array
 * @left_array: the first merged array
 * @left_size: length of the first merged array
 * @right_array: the second merged array
 * @right_size: length of the second merged array
 * @merged_array: the merged array
 */
void merge(int *left_array, size_t left_size, int *right_array,
		size_t right_size, int *merged_array)
{
	size_t i = 0, j = 0, k = 0;

	/* merges the two sorted sub-arrays into a single sorted array */
	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
			merged_array[k++] = left_array[i++];
		else
			merged_array[k++] = right_array[j++];
	}
	/* if left array's length is less than that of the right */
	while (i < left_size)
		merged_array[k++] = left_array[i++];

	/* if right array's length is less than that of the left */
	while (j < right_size)
		merged_array[k++] = right_array[j++];

	printf("%s\n", "Merging...");
	printArray(left_array, left_size, "left");
	printArray(right_array, right_size, "right");
	printArray(merged_array, k, "Done");
}

/**
 * create_list - creates a list with malloc
 * @size: size of the array
 *
 * Return: an array
 */
int *create_list(int size)
{
	return (malloc(sizeof(int) * size));
}

/**
 * free_list - frees an array created with malloc
 * @array: array to be free
 */
void free_list(int *array)
{
	free(array);
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 *		top-down `Merge sort` algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left_array, *right_array;

	if (size <= 1)
		return;

	mid = size / 2;

	left_array = create_list(mid);
	right_array = create_list(size - mid);

	for (i = 0; i < mid; i++)
		left_array[i] = array[i];

	for (i = mid; i < size; i++)
		right_array[i - mid] = array[i];

	merge_sort(left_array, mid);
	merge_sort(right_array, size - mid);
	merge(left_array, mid, right_array, size - mid, array);

	free_list(left_array);
	free_list(right_array);
}
