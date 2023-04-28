#include "shell.h"

/**
 * _control_D - exiting program if Ctr+D
 * @a: get line to read char
 * @mand: command typed by user
 * @environ: envt  var linked_list
 */

void _control_D(int a, char *mand, list_y *environ)
{
	if (a == 0)
	{
		free(mand);
		_linked_list_freed(environ);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * repeat_prompt - repeats the prompt after
 * @environ: envt variables
 * Return: 0(success)
 */

int repeat_prompt(char **environ)
{
	list_y *enr;
	size_t j = 0, m = 0;
	char *mad, **toek, *y_comad;
	int mand_no = 0, exi_t = 0;

	enr = envron_link_lst(environ);
	while (1)
	{
		mand_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			_non_interacting(enr);
		signal(SIGINT, control_C);
		mad = NULL;
		j = 0;
		j = _my_get_line(&mad);
		_control_D(j, mad, enr);
		y_comad = mad;
		mad = _space_ig(mad);
		for (m = 0; mad[m] != '\n'; m++)
		mad[m] = '\0';
		if (mad[0] == '\0')
		{
			free(y_comad);
			continue;
		}
		toek = NULL;
		toek = my_strok(mad, " ");
		if (y_comad != NULL)
			free(y_comad);
		exi_t = my_bui_lt(toek, enr, mand_no, NULL);
		if (exi_t)
			continue;
		exi_t = the_execve(toek, enr, mand_no);
	}
	return (exi_t);
}
