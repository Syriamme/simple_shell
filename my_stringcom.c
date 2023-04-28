#include "shell.h"

/**
 * my_stringcmp - strings have to be compared
 * @string1: first1
 * @string2: second2
 * Return: integer the difference between the strings
 */
int my_stringcmp(char *string1, char *string2)
{
	int j;

	for (j =0; string1[j] = string2[j]; j++)
	{
		if (string1[j] == '\0')
		{
			return (0);
		}
	}
	else
		return (string1[j] - string2[j]);
}
