#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			listint_t *prev = temp->prev;
			listint_t *next = temp->next;

			/* Move temp before prev */
			if (prev->prev != NULL)
				prev->prev->next = temp;
			temp->prev = prev->prev;

			temp->next = prev;
			prev->prev = temp;

			prev->next = next;
			if (next != NULL)
				next->prev = prev;

			/* Update head */
			if (temp->prev == NULL)
				*list = temp;

			print_list(*list);
		}

		current = current->next;
	}
}
