#include "shell.h"

/**
 * _nodeint_delete_at_index - deleting a node at a certain index
 * @head: holding address of node
 * @ixe: index input
 * Return: 1 if success, -1 if fail
 */
int _nodeint_delte_at_index(list_y **head, int ixe)
{
	int sum = 0;
	list_y *x_head;
	list_y *hdr;

	if (*head == NULL)
	{
		return (-1);
	}
	if (ixe == 0)
	{
		hdr = (*head)->next;
		free((*head)->varib);
		free(*head);
		*head = hdr;
		return (1);
	}
	sum = 1;
	x_head = *head;
	while (sum < ixe)
	{
		if (x_head == NULL)
			return (-1);
		x_head = x_head->next;
		sum++;
	}
	hdr = x_head->next;
	x_head->next = hdr->next;
	free(hdr->varib);
	free(hdr);
	return (1);
}

/**
 * _linked_list_freed - a function that gets linked list free
 * @thelist: the linked list
 */
void _linked_list_freed(list_y *thelist)
{
	list_y *hdr;

	while (thelist != NULL)
	{
		hdr = thelist;
		thelist = thelist->next;
		free(hdr->varib);
		free(hdr);
	}

}
