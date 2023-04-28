#include "shell.h"

/**
 *com_exit - freeing the command and link_list
 * @pointer: the command typed
 * @environ: The linked_list envt var
 * Return: 0 for success
 */
void com_exit(char **pointer, list_y *environ)
{
	double_pt_free(pointer);
	_linked_list_freed(environ);
	exit(0);
}

/**
 * the_execve - command executor
 * @ptr: command typed
 * @environ: variable
 * @number: nth command with an errror message
 * Return: 0 for success
 */
int the_execve(char **ptr, list_y *environ, int number)
{
	pid_t pid;
	char *hdr;
	int stat = 0;
	int a  = 0;

	if (access(ptr[0], F_OK) == 0)
	{
		hdr = s[0];
		a = 1;
	}
	
	else
		hdr = my_whic(ptr[0], environ);
	
	
	if (access(hdr, X_OK) != 0)
	{
		found_not(s[0], number, environ);
		double_ptr_free(ptr);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(hdr, ptr, NULL) == -1)
			{
				found_not(ptr[0], number, environ);
				com_exit(ptr, environ);
			}
		}
		else
		{
			wait(&stat);
			double_ptr_free(ptr);
			if (a == 0)
				free(hdr);
		}
	}
	return (0);
}
