#include "shell.h"

/**
 * my_strnlen - string length count
 * @pointer: pointer to the token
 * @point: user command position
 * @delimeter: delimeter (e.g. " ");
 * Return: token length
 */
int my_strnlen(char *pointer, int point, char delimeter)
{
	int length = 0;

	while (pointer[point] != delimeter && pointer[point] != '\0')
	{
		point++;
		length++;
	}
	return (length);
}

/**
 * m_t_sze - a function to for delim
 * @pointer: command
 * @delimet: the delimeter;
 * Return: delim numbers
 */
int m_t_sze(char *pointer, char delimet)
{
	int j = 0;
	int nm_del = 0;

	while (pointer[j] != '\0')
	{
		if ((pointer[j] == delimet) && (pointer[j + 1] != delimet))
		{
			nm_del++;
		}
		if ((pointer[j] == delimet) && (pointer[j + 1] == '\0'))
		{
			nm_del--;
		}
		j++;
	}
	return (nm_del);
}


/**
 *_delimeter_ig - avoids the previous delimeters
 * @pointer: the string
 * @delimeta: delimiter
 * Return: the current string
 */

char *_delimeter_ig(char *pointer, char delimeta)
{
	while (*pointer == delimeta)
		pointer++;
	return (pointer);
}
