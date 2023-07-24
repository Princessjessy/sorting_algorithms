#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm
 * @list: A double pointer to the first node of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node = NULL, *next_node = NULL, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		temp = current_node;
		while (temp->prev && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		current_node = next_node;
	}
}
