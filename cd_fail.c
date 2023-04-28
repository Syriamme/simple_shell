#include "shell.h"

/**
 * cd_fail -function for cd error
 * @pointer: arg after cmd
 * @nt: command nth
 * @environ: envt var
 * Return: Always 0  succes
 */

void cd_fail(char *pointer, int nt, list_y *environ)
{
	char *sel;
	char *nuber;
	int sum =0;

	sel = my_get_enr("_", environ);
	
	while (sel[sum] != '\0')
		sum++;
	write(STDOUT_FILENO, sel, sum);
	free(sel);
	
	write(STDOUT_FILENO, ": ", 2);
	nuber = integ_string(nt);
	
	for (sum = 0; nuber[sum] != '\0'; sum++)
		;
	
	write(STDOUT_FILENO, nuber, sum);
	free(sel);
	
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: cannot cd ", 14);
	
	for (sum = 0; pointer[sum] != '\0'; sum++)
		;
	write(STDOUT_FILENO, pointer, sum);
	
	write(STDOUT_FILENO, "\n", 1);
}


/**
 * _wrong_number - error for wrong number
 * @str: command typed
 * @nt: the command after cmd
 * @eniron: the envt var
 */

void _wrong_number(char *pointer, int nt, list_y *environ)
{
	char *sel = NULL;
	char *nuba = NULL;
	int sum = 0;
	
	sel = my_get_enr("_", environ);
	
	while (sel[sum] != '\0')
		sum++;
	
	write(STDOUT_FILENO, sel, sum);
	free(sel);
	
	write(STDOUT_FILENO, ": ", 2);
	nuba = integ_string(nt);
	
	for (sum = 0; nuba[sum] != '\0'; sum++)
		write(STDOUT_FILENO, nuba, sum);
	free(nuba);
	
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "exit: wrong number: ", 20);
	
	for (sum = 0; pointer[sum] != '\0'; sum++)
		write(STDOUT_FILENO, pointer, sum);
	
	write(STDOUT_FILENO, "\n", 1);
}
