#include "shell.h"

/**
 * my_str_dp - a function for string dup,
 * @pointer: duplicate string
 * Return: duplicated string pointer
 */
char *my_str_dp(char *pointer)
{
	char *dup_string;
	int j;
	int length = 0;

	if (pointer == NULL)
		return (NULL);

	while (*(pointer + length))
		length++;
	length++;
	dup_string = malloc(sizeof(char) * length);
	
	if (dup_string == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < length; j++)
	{
		*(dup_string + a) = *(pointer + j);
		j++;
	}

	return (dup_string);
}
