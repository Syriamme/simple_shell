#include "shell.h"

/**
 * main - Main function for simple shell
 * @agrc: the arg_count
 * @argv: the arg vector
 * @environ: env var
 * Return: 0 if successfull
 */

int main(int argc, char **argv, char **environ)
{
	(void)argv;

	(void)argc;

	prompt(environ);

	return (0);
}
