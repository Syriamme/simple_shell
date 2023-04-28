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
	int length;

	for (length = 0; (pointer[point] != delimeter) && (pointer[point] != '\0'); length++)
	{
		point++;
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
 * _delimeter_ig - avoids the previous delimeters 
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

/**
 *my _strok -  string tokenization
 * @pointer: command typed
 * @delimeta: delimeter
 * Return: token array
 */
char **my_strok(char *pointer, char *delimeta)
{
	int bufze = 0;
	int o = 0;
	int zip = 0;
	int j = 0;
	int length = 0;
	int zep = 0;
	int q = 0;
	char **token = NULL, c_sh;

	c_sh = delimeta[0];
	pointer = _delimeter_ig(pointer, c_sh);
	
	bufze = m_t_sze(pointer, c_sh);
	token = malloc(sizeof(char *) * (bufze + 2));
	
	if (token == NULL)
		return (NULL);
	
	while (pointer[zep] != '\0')
		zep++;
	while (zip < zep)
	{
		if (pointer[zip] != c_sh)
		{
			length = my_strnlen(pointer, zip, c_sh);
			token[o] = malloc(sizeof(char) * (length + 1));
			if (token[o] == NULL)
				return (NULL);
			for(j = 0; pointer[zip] != c_sh && pointer[zip] != '\0'; j++)
			{
				token[o][j] = pointer[zip];
				zip++;
			}
			token[o][j] = '\0';
			q++;
		}
		
		if (zip < zep && (pointer[zip + 1] != c_sh && pointer[zip + 1] != '\0'))
			o++;
		zip++;
	}
	o++;
	token[o] = NULL;
	return (token);
}
