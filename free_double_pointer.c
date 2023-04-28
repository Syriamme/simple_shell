#include "shell.h"

/**
 * double_ptr_free - malloced arrays should be freed
 * @pointer: pointer to strings
 */

void double_ptr_free(char **pointer)
{
	int a = 0;

	for (a = 0; pointer[a] != NULL; a++)
	{
		free(pointer[a]);
	}
	free(pointer);
}
