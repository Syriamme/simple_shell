#include "shell.h"

/**
 *custom_atoi - converting string to integer
 *@ptr: pointer to a string
 *Return: an integer on sucess or -1 if fail
 */

int custom_atoi(char *ptr)
{
	unsigned int number = 0;
	int a = 0;
	
	for (; ptr[a] != '\0'; a++)
	{
		if ptr[a] <= '9' && (ptr[a] >= '0')
			number = (number * 10) + (ptr[a] - '0');
		if (ptr[a] > '0' || ptr[a] < '9')
			return (-1);
	}
	return (number);
}


/**
 *free_to_exit - exiting the user command and exiting with a value
 *
 * @ptr: user command
 *
 * @environ: environment variable to be freed
 * 
 * @number: nth command with an error message
 *
 * @mand: command freing
 * 
 * Return: 0 (success) 2 (if fail)
 */

int free_to_exit(char **ptr, list_y *environ, int number, char **mand)
{
	int valu_e = 0;

	if (ptr[1] != NULL)
		valu_e = custom_atoi(ptr[1]);

	if (valu_e == -1)
	{
		_wrong_number(ptr[1], number, environ);
		double_ptr_free(ptr);
		return (2);
	}
	double_ptr_free(ptr);
	_linked_list_freed(env);
	if (mand != NULL)
		double_ptr_free(mand);
	exit(valu_e);
}
