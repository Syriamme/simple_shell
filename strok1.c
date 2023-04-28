#include "shell.h"

/**
 *my_strok -  string tokenization
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
			for (j = 0; pointer[zip] != c_sh && pointer[zip] != '\0'; j++)
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
