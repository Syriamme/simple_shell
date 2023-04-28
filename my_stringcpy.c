#include "shell.h"

/**
 * my_stringcpy - strings must be copied
 * @second: the second string to be copied to
 * @first: the first string to copy from
 * Return: the copy of first string
 */

char *my_stringcpy(char *second, char *first)
{
	int j;
	int length;

	for (length = 0; first[length] != '\0'; length++)
		;

	for (j = 0; j <= length; j++)
		second[j] = first[j];

	return (second);
}
