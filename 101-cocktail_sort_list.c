#include "sort.h"

/**
 * swap_list_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to a pointer to current position of a linked list
 */
void swap_list_nodes(listint_t **list)
{
	listint_t *current_list, *next_node, *prev_node;

	current_list = *list;
	next_node = current_list->next;
	prev_node = current_list->prev;
	current_list->next = next_node->next;
	current_list->prev = next_node;
	if (next_node->next != NULL)
		next_node->next->prev = current_list;
	next_node->next = current_list;
	next_node->prev = prev_node;
	if (prev_node != NULL)
		prev_node->next = next_node;
}

/**
 * cocktail_sort_list - uses cocktail sort algorithm on a double linked list
 * @list: double linked list sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped, current_val, next_val;
	listint_t *current_list;

	current_list = *list;
	swapped = 0;
	do {
		while (current_list->next != NULL)
		{
			current_val = current_list->n;
			next_val = current_list->next->n;
			if (current_val > next_val)
			{
				swap_list_nodes(&current_list);
				swapped = 1;
				print_list(*list);
			}
			else
				current_list = current_list->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (current_list->prev != NULL)
		{
			current_val = current_list->n;
			next_val = current_list->prev->n;
			if (current_val < next_val)
			{
				swap_list_nodes(&(current_list->prev));
				swapped = 1;
				if (current_list->prev == NULL)
					*list = current_list;
				print_list(*list);
			}
			else
				current_list = current_list->prev;
		}
	} while (swapped == 1);
}
