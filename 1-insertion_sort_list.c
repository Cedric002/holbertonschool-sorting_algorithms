#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly
 * linked list in ascending order
 * list: doubly linked list
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	if (*list == NULL)
		*list = current;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		current = temp;
	}
}
