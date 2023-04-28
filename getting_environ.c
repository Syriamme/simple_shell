#include "shell.h"

/**
 *custom_strdp - string duplicate function
 *@pointer: pointer to a string to duplicate
 *@nth: bytes being excluded
 *Return: the string
 */

char *custom_strdp(char *pointer, int nth)
{
	char *dup_string;
	int a;
	int length = 0;

	if (pointer == NULL)
		return (NULL);
	while (*(pointer + length))
		length++;
	length++;

	dup_string = malloc(sizeof(char) * (length - nth));
	if (dup_string == NULL)
		return (NULL);
	for (a = 0; a < length - nth; a++)
	{
		*(dup_string + a) = *(pointer + nth + a);
	}
	return (dup_string);
}


/**
 * my_get_enr - returning the envt variable copy
 *@pointer: pointer to a string
 * @environ: environment varaible set
 *Return: environ requested
 */

char *my_get_enr(char *pointer, list_y *environ)
{
	int b = 0;
	int nth = 0;

	while (environ != NULL)
	{
		for (b = 0; (environ->varib)[b] == pointer[b]; b++)
		{
			if ((environ->varib)[b] == '=' && pointer[b] == '\0')
				break;
			environ = environ->next;
		}
	}
	while (pointer[nth] != '\0')
		nth++;
	nth++;
	return (custom_strdp(environ->varib, nth));
}
