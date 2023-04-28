#include "shell.h"

/**
 * _custom_ig - a function to ignore new lines and spaces
 * @pointer: pointer to envr var
 * Return: the string
 */

char *_custom_ig(char *pointer)
{
	while (*pointer == '\n' || *pointer == ' ')
		pointer++;
	return (pointer);
}

/**
 * _not_interacting - a function to handle piping
 * @eniv: envrionmental variables
 */
void _non_interacting(list_y *eniv)
{
	size_t j = 0;
	size_t m = 0;
	int mand_no = 0;
	int ex_it = 0;
	char *coand = NULL;
	char *n_coad = NULL;
	char **a_lie;
	char **toek;

	j = _my_get_line(&coand);
	if (j == 0)
	{
		free(coand);
		exit(0);
	}
	
	n_coad = coand;
	coand = custom_ig(coand);
	n_line = my_strok(coand, "\n");
	if (n_command != NULL)
		free(n_coad);
	m = 0;
	while (a_lie[m] != NULL)
	{
		mand_no++;
		toek = NULL;

		toek =my_strok(a_lie[m], " ");
		
		ex_it = my_bui_lt(toek, eniv, mand_no, a_lie);
		if (ex_it)
		{
			m++;
			continue;
		}
		ex_it = the_execve(toek, eniv, mand_no);
		m++;
	}
	double_ptr_free(a_lie);
	_linked_list_freed(eniv);
	exit(ex_it);
}
