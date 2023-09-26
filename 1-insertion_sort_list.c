#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list using Insertion sort
 * @list: double pointer to the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp, *current;

	if (!list || !(*list))
		return;

	node = current = *list;

	while (current)
	{
		if (current->prev && (current->prev)->n > current->n)
		{
			node = current;
			current = current->prev;
			while (node->prev && (node->prev)->n > node->n)
			{  /* Insert node at the correct position */
				tmp = node->prev;
				if (!tmp->prev)
					*list = node;  /* Update the head */
				if (node->next)
					node->next->prev = tmp;
				if (tmp->prev)
					tmp->prev->next = node;
				node->prev = tmp->prev;
				tmp->next = node->next;
				node->next = tmp;
				tmp->prev = node;
				print_list(*list);
			}
		}

		current = current->next;
	}
}
