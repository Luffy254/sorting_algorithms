#include "sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @head: head of list@list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1, *next1, *prev2, *next2;

	if (node1 == NULL || node2 == NULL)
		return;

	prev1 = node1->prev;
	next1 = node1->next;
	prev2 = node2->prev;
	next2 = node2->next;

	if (prev1)
		prev1->next = node2;
	if (next1)
		next1->prev = node2;
	if (prev2)
		prev2->next = node1;
	if (next2)
		next2->prev = node1;

	node1->next = next2;
	node1->prev = prev2;
	node2->next = next1;
	node2->prev = prev1;

	if (prev1 == NULL)
		*list = node2;
	if (prev2 == NULL)
		*list = node1;
}

/**
 * insertion_sort_list - sorts doubly linked list in ascending order
 * @list: pointer to the head of list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;

	listint_t *curr, *prev;

	curr = (*list)->next;

	while (curr != NULL)
	{
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			swap_nodes(list, prev, curr);
			print_list(*list);
			prev = curr->prev;
		}
		curr = curr->next;
	}
}
