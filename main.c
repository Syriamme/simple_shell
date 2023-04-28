#include "shell.h"

/**
 *main - main function for simple shell
 *@argc:the arg_count
 *@argv:the arg vector
 *@environ:env var
 * Return:0 if successfull
 */

int main(int argc, char **argv, char **environ)
{
	(void)argv;

	(void)argc;
	repeat_prompt(environ);

	return (0);
}
