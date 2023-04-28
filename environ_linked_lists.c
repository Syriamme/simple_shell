#include "shell.h"
/**
 * envron_link_lst - creating a linked list
 * @environ: the variables
 * Return: list_t
 */

list_y *envron_link_lst(char **environ)
{
	int a = 0;
	list_y *head;

	for (head = NULL; environ[a] != NULL; a++)
	{
		end_node_add(&head, environ[a]);
	}
	return (head);
}


/**
 * print_envt - printing variables
 * @ptr: shell command
 * @environ: environ variables
 * Return: Zero(0) on success
 */


int print_envt(char **ptr, list_y *environ)
{
	double_ptr_free(ptr);
	_list_print(environ);
	return (0);
}
