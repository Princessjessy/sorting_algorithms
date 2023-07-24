#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int partition(int *array, int low, int high, int size);
void sort(int *array, int low, int high, int size);
int hoare_partition(int *arr, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);
void quick_sort_h(int *array, int low, int high, size_t size);
void insertion_sort_list(listint_t **list);
void merge_sort(int *array, size_t size);
void merge(int *left_array, size_t left_size, int *right_array,
		size_t right_size, int *merged_array);
void printArray(int *array, int array_size, char *desc);
int *create_list(int size);
void free_list(int *array);
void counting_sort(int *array, size_t size);
int max_int(int *array, size_t size);
int *createArray(size_t size);

#endif
