#include "shell.h"

/**
 * found_not - error function
 * @pointer: the command from user
 * @nth: the command nth typed
 * @environ: envt vriable
 *Return: Always 0 (success)
 * */

void found_not(char *pointer, int nth, list_y *environ)
{
	char *sel;
	char *nuber;
	int sum = 0;

	sel = my_get_enr("_", environ);
	
	for (; sel[sum] != '\0'; sum++)
		;
	write(STDOUT_FILENO, sel, sum);
	free(sel);
	
	write(STDOUT_FILENO, ": ", 2);
	nuber = integ_string(nth);
	
	for (sum = 0; nuber[sum] != '\0'; sum++)
		;
	
	write(STDOUT_FILENO, nuber, sum);
	free(nuber);
	write(STDOUT_FILENO, ": ", 2);
	
	for (sum = 0; pointer[sum] != '\0'; sum++)
		;
	write(STDOUT_FILENO, pointer, sum);
	
	write(STDOUT_FILENO, ": ", 2);
	
	write(STDOUT_FILENO, "not such\n", 8);
}
