#include "shell.h"

/**
 * control_C -ignore Ctrl-C input and prints prompt again
 * @y: takes in int from signal
 */

void control_C(int y)
{
	(void)y;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 *my_bui_lt - a function builtins handling
 *@toek: command typed by user
 *
 *@number: the write error messsage take in by user
 *@environ: envnt var
 *
 *@mand: freeing command
 *Return: 1 if success, 0 on failure
 */

int my_bui_lt(char **toek, list_y *environ, int number, char **mand)
{
	int a = 0;

	if (my_stringcmp(toek[0], "exit") == 0)
	{
		a = free_to_exit(toek, environ, number, mand);
	}
	else if (my_stringcmp(toek[0], "env") == 0)
	{
		print_envt(toek, environ);
		a = 1;
	}
	else if (my_stringcmp(toek[0], "cd") == 0)
	{
		a = my_changedir(toek, environ, number);
	}
	else if (my_stringcmp(toek[0], "setenv") == 0)
	{
		my_set_env(&environ, toek);
		a = 1;
	}
	else if (my_stringcmp(toek[0], "unsetenv") == 0)
	{
		un_env(&environ, toek);
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
		pointer++;
	}
	return (pointer);
}
