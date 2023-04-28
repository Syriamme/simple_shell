#include "shell.h"

/**
 *my_stringcat - concat strings
 *@dest: first string
 *@src: second string
 *Return: final concatenated string
 */
char *my_stringcat(char *second char *first)
{
	int length = 0, length2 = 0;
	int sum_length = 0, k = 0;

	while (second[length] != '\0')
	{
		length++;
		sum_length++;
	}
	
	while (first[length2] != '\0')
	{
		length2++;
		sum_length++;
	}

	second = _my_realloc(second, length, sizeof(char) * sum_length + 1);

	for (; first[k] != '\0'; k++)
	{
		second[length] = first[k];
		length++;
	}
	second[length] = '\0';

	return (second);
}
