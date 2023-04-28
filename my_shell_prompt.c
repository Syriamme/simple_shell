#include "shell.h"

/**
 * control_C - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */

void control_C(int y)
{
	(void)y;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * my_bui_lt - a function builtins handling
 * @toek: command typed by user
 * @number: the write error messsage take in by user
 * @environ: envnt var
 * @mand: freeing command
 * Return: 1 if success, 0 on failure
 */

int my_bui_lt(char **toek, list_y *environ, int number, char **mand)
{
	int a = 0;

	if (my_strcmp(toek[0], "exit") == 0)
	{
		a = my_exit(toek, environ, num, mand);
	}
	else if (my_strcmp(token[0], "env") == 0)
	{
		my_gtenv(toek, environ);
		a = 1;
	}
	else if (my_strcmp(toek[0], "cd") == 0)
	{
		a = my_changedir(toek, environ, number);
	}
	else if (my_strcmp(toek[0], "setenv") == 0)
	{
		my_set_env(&environ, toek);
		a = 1;
	}
	else if (my_strcmp(toek[0], "unsetenv") == 0)
	{
		_un_env(&environ, toek);
		a = 1;
	}
	return (a);
}


/**
 * _space_ig - a function to ignore spaces infront
 * @pointer: pointer to a string
 *
 * Return: new string
 */

char *_space_ig(char *pointer)
{
	while (*pointer == ' ')
	{
		pointer ++;
	}
	return (pointer);
}


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
		linked_list_freed(env);
		
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

	environ = _linked_list_envt(enr);
	do {
		mand_no++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		else
			_non_interacting(environ);
		signal(SIGINT, control_C);
		mand = NULL;
		
		j = 0;
		j = _my_get_line(mad);
		
		_control_D(j, mad, environ);
		y_comad = mad;
		mad = _space_ig(mad);
		
		for (m = 0; mad[m] != '\n'; n++);
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
		exi_t = the_bui_lt_in(toek, environ, mand_no, NULL);
		
		if (exi_t)
			continue;
		exi_t = the_execve(toek, environ, mand_no);
	} while (1)
	return (exi_t);
}
