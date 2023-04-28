#include "shell.h"

/**
 *_my_realloc - function for reallocating memory
 * @pointer: pointing to the malloc
 * @prev: last size
 * @current: reallocated memory
 * Return: reallocated memory pointer
 */

void *_my_realloc(void *pointer, unsigned int prev, unsigned int current)
{
	unsigned int a;
	void *ptr;

	if (pointer != NULL && current == 0)
	{
		free(pointer);
		return (NULL);
	}

	if (current == prev)
		return (pointer);

	if (pointer == NULL)
	{
		ptr = malloc(current);
		if (ptr == NULL)
			return (NULL);
		else
			return (ptr);
	}

	ptr = malloc(current);
	if (ptr == NULL)
		return (NULL);
	a = 0;
	while (a < current && a < prev)
	{
		*((char *)ptr + a) = *((char *)pointer + a);
		a++;
	}
	free(pointer);
	return (ptr);
}
