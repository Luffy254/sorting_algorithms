#include "sort.h"
/**
  * swap_node -used to make the swap
  *
  * @db_list: the list passed doubly linked list
  * @node1: the current node
  * Return: current node
  */
listint_t *swap_node(listint_t **db_list, listint_t *node1)
{
	listint_t *prev_node;

	prev_node = node1->prev;
	prev_node->next = node1->next;

	if (node1->next != NULL)
		node1->next->prev = prev_node;

	node1->prev = prev_node->prev;
	prev_node->prev = node1;
	node1->next = prev_node;

	if (node1->prev == NULL)
		*db_list = node1;
	return (node1);
}
/**
  * insertion_sort_list - sorts doubly linked list in ascending order
  *
  * @list: pointer to the head of list
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *node1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
	{
		return;
	}

	node1 = (*list)->next;
	while (node1 != NULL)
	{
		while (node1->prev != NULL && (node1->n < node1->prev->n))
		{
			node1 = swap_node(list, node1);
			print_list(*list);
		}
		node1 = node1->next;
	}
}
