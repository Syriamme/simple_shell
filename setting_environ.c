#include "shell.h"

/**
 * my_gtenv - get envt var in linked_lst
 * @environ: envt var
 * @pointer: var name
 * Return: idx of node in linked list
 */
int my_gtenv(list_y *environ, char *pointer)
{
	int ixe = 0;
	int k = 0;

	while (environ != NULL)
	{
		k = 0;
		while ((environ->varib)[k] == pointer[k])
			k++;
		if (pointer[k] == '\0')
			break;
		environ = environ->next;
		ixe++;
	}
	if (environ == NULL)
		return (-1);
	return (ixe);
}

/**
 * un_env - unset the env var linked_lst
 * @environ: the linked_list to remove
 * @pointer: command typed
 * Return: 0 if sucesss or -1 if failure
 */
int un_env(list_y **environ, char **pointer)
{
	int ixe = 0;
	int k = 0;

	if (pointer[1] == NULL)
	{
		write(STDOUT_FILENO, "few args passed\n", 15);
		double_ptr_free(pointer);
		return (-1);
	}
	ixe = my_gtenv(*environ, pointer[1]);

	double_ptr_free(pointer);

	if (ixe == -1)
	{
		write(STDOUT_FILENO, "Can't get\n", 8);
		return (-1);
	}

	k = _nodeint_delte_at_index(environ, ixe);

	if (k == -1)
	{
		write(STDOUT_FILENO, "Can't get\n", 8);
		return (-1);
	}
	return (0);
}
