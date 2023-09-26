#include "sort.h"

/**
 * swap_with_next - swap the current node with the next one
 * @current: pointer to the node to be swapped
 * @list: double pointer to the head of the linked list
 */
void swap_with_next(listint_t *current, listint_t **list)
{
	listint_t *tmp;

	if (!current || !list || !(*list))
		return;

	if (!current->prev)  /* Update the head */
		*list = current->next;
	tmp = current->next;
	current->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = current;
	tmp->prev = current->prev;
	if (current->prev)
		current->prev->next = tmp;
	current->prev = tmp;
	tmp->next = current;
}

/**
 * swap_with_prev - swap the current node with the previous one
 * @current: pointer to the node to be swapped
 * @list: double pointer to the head of the linked list
 */
void swap_with_prev(listint_t *current, listint_t **list)
{
	listint_t *tmp;

	if (!current || !list || !(*list))
		return;

	tmp = current->prev;
	if (!tmp->prev)
		*list = current;  /* Update the head */
	if (current->next)
		current->next->prev = tmp;
	if (tmp->prev)
		tmp->prev->next = current;
	current->prev = tmp->prev;
	tmp->next = current->next;
	current->next = tmp;
	tmp->prev = current;
}

/**
 * cocktail_sort_list - sort a doubly-linked list using Cocktail Shaker sort
 * @list: double pointer to list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *low, *high;
	int swapped;

	if (!list || !(*list))
		return;

	current = *list;
	do {
		swapped = 0;
		while (current->next && current->next != high)
		{  /* Forward pass */
			if (current->n > current->next->n)
			{
				swap_with_next(current, list);
				high = current;
				print_list(*list);
				swapped = 1;
				continue;
			}
			current = current->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current->prev && current->prev != low)
		{  /* Backward pass */
			if (current->n < current->prev->n)
			{
				swap_with_prev(current, list);
				print_list(*list);
				low = current;
				swapped = 1;
				continue;
			}
			current = current->prev;
		}
	} while (swapped == 1);
}
