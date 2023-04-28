#include "shell.h"

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
		write(STDOUT_FILENO, "few args\n", 7);
		double_ptr_free(pointer);
		return (-1);
	}
	cpyca = my_str_dp(pointer[1]);
	cpyca = my_stringcat(cpyca, "=");
	cpyca = my_stringcat(cpyca, pointer[2]);
	ixe = my_gtenv(*environ, pointer[1]);
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
