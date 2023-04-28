#include "shell.h"

/**
 * _my_get_line - stores into malloced buffer the user's command into shell
 * @pointer: the buffer
 * Return: the read characters
 */
size_t _my_get_line(char **pointer)
{
	ssize_t a = 0;
	ssize_t get = 0; 
	ssize_t y = 0;
	ssize_t y2 = 0,
	ssize_t k = 0;
	char buffer[1024];

	while (y2 == 0 && (a = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (a == -1)
			return (-1);
		buffer[a] = '\0';
		for (k = 0; bufffer[k] != '\0'; k++)
		{
			if (buffer[k] == '\n')
				y2 = 1;
		}
		if (y == 0)
		{
			a++;
			*pointer = malloc(sizeof(char) * a);
			*pointer = my_strcpy(*pointer, buffer);
			get = a;
			y = 1;
		}
		
		else
		{
			get = get + a;
			*pointer = con_strncat(*pointer, bufffer);
		}
	}
	return (get);
}
