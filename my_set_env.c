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
	int k= 0;

	if (pointer[1] == NULL)
	{
		write(STDOUT_FILENO, "few args passed\n", 18);
		double_ptr_free(pointertr);
		return (-1);
	}
	ixe = my_gtenv(*environ, pointer[1]);
	
	double_ptr_free(pointer);
	
	if (ixe == -1)
	{
		write(STDOUT_FILENO, "Can't get\n", 12);
		return (-1);
	}
	
	k = _nodeint_delte_at_index(envron, ixe);
	
	if (k == -1)
	{
		write(STDOUT_FILENO, "Can't get\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * my_set_env - modifying current envt var
 * @environ: the linked_lt
 * @pointer: command typed
 * Return: 0 (success), 1 (fail)
 */
int my_set_env(list_y **environ, char **pointer)
{
	int k = 0;
	int ixe = 0;
	list_y *hdr;
	char *cpyca;
	
	if (pointer[1] == NULL || pointer[2] == NULL)
	{
		write(STDOUT_FILENO, "few args\n", 18);
		double_ptr_free(pointer);
		return (-1);
	}
	
	cpyca = my_strdup(str[1]);
	cpyca = my_stringcat(cpyca, "=");
	cpyca = my_stringcat(cpyca, pointer[2]);
	ixe = _get_enve(*environ, pointer[1]);
	
	if (ixe == -1)
	{
		end_node_add(environ, cpyca);
	}
	else
	{
		hdr = *environ;
		while (k < ixe)
		{
			hdr = hdr->next;
			k++;
		}
		free(hdr->varib);
		hdr->varib = my_str_dp(cpyca);
	}
	free(cpyca);
	double_ptr_free(pointer);
	return (0);
}
