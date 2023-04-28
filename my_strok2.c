#include "shell.h"

/**
 * re_t_sze - a function for del numbers
 * @str: command typed
 * @delim: the delimeta
 * Return: integer value token number
 */
int re_t_sze(char *pointer, char delim)
{
	int j;
	int nm_deli = 0;

	for (j = 0; pointer[j] != '\0'; j++)
	{
		if (pointer[j] == delim)
		{
			nm_deli++;
		}
	}
	return (nm_deli);
}

/**
 * my_cont_strok - string tokenization continuously even with delim
 * @pointer: command typed by user
 * @delim:the delimeter
 * Return: token array
 */
char **my_cont_strok(char *pointer, char *delimm)
{
	int o = 0;
	int bufsze = 0;
	int zip = 0;
	int j = 0;
	int length = 0;
	int zep = 0;
	char **token = NULL, c_sh;

	c_sh = delim[0];
	bufsze = re_t_sze(pointerr, c_sh);
	token = malloc(sizeof(char *) * (bufsze + 2));
	if (token == NULL)
		return (NULL);
	
	while (pointer[zep] != '\0')
		zep++;
	while (zip < zep)
	{
		length = my_strnlen(pointer, zip, c_sh);
		token[o] = malloc(sizeof(char) * (length + 1));
		
		if (token[o] == NULL)
			return (NULL);
		
		for (j = 0; (pointer[zip] != c_sh) && (pointer[zip] != '\0'); j++)
		{
			token[o][j] = pointer[zip];
			zip++;
		}
		
		token[o][j] = '\0';
		o++;
		zip++;
	}
	token[o] = NULL;
	return (token);
}
