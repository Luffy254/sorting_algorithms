#include "sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @head: head of list@list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */

void swap_nodes(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *auxy1, *auxy2;

	if (node1 == NULL || node2 == NULL)
		return;

	auxy1 = node1->prev;
	auxy2 = node2->next;

	if (auxy1)
		auxy1->next = node2;
	if (auxy2)
		auxy2->prev = node1;

	node1->next = auxy2;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = auxy1;

	if (auxy1 == NULL)
		*head = node2;
}

/**
 * insertion_sort_list - sorts doubly linked list in ascending order
 * @list: pointer to the head of list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev;
	int val;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;

	curr = *list;
	while (curr)
	{
		prev = curr->prev;
				val = curr->n;

		while (prev && prev->n > val)
		{
			swap_nodes(prev, curr, list);
			print_list(*list);
			prev = curr->prev;
		}
		curr = curr->next;
	}
}
