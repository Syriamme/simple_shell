#include "shell.h"

/**
 * _list_print - linked list must be printed
 * @nth: this is the linked list
 * Return: the linked list size
 */
size_t _list_print(list_y *nth)
{
	list_y *h_list = nth;
	int sum = 0, a = 0;

	if (nth == NULL)
		return (0);
	
	for (; h_list != NULL; sum++)
	{
		if (h_list->varib == NULL)
		{
			write(STDOUT_FILENO, "(nil)", 5);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			for (a = 0; ((h_list->varib)[a] != '\0'; a++);
					write(STDOUT_FILENO, h_list->varib, a);
					write(STDOUT_FILENO, "\n", 1);
		}
		h_list = h_list->next;
	}
	return (sum);
}


/**
 * end_node_add - this function will add a node
 * @head: head of linked list pointer
 * @pointer: new node data
 * Return: new node pointer
 */
list_y *end_node_add(list_y **head, char *pointer)
{
	list_y *hdr, *new_node;

	if (*pointer == NULL || *head == NULL)
		return (NULL);
	
	new_node = malloc(sizeof(list_t));
	
	if (new_node == NULL)
		return (NULL);
	
	new_node->varib = my_strdup(pointer);
	new_node->next = NULL;

	hdr = *head;
	
	if (hdr != NULL)
	{
		while (hdr->next != NULL)
		{
			hdr = hdr->next;
		}
		hdr->next = new_node;
	}
	
	else
	{
		*head = new_node;
	}
	return (*head);
}


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
	while (sum < index)
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
