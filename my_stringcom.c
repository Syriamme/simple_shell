#include "shell.h"

/**
 * my_stringcmp - strings have to be compared
 * @string1: first1
 * @string2: second2
 * Return: integer the difference between the strings
 */
int my_stringcmp(char *string1, char *string2)
{
	while (*string1 == *string2)
	{
		if (*string1 == '\0')
		{
			return (0);
		}
		string1++;
		string2++;
	}
	return (*string1 - *string2);
}
