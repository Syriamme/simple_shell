#include "shell.h"

/**
 * con_strncat - concatenating two strings
 * @dest: appending string to
 * @src: appended string
 * Return: stringconcatenated
 */

char *con_strncat(char *destiny, char *sourc)
{
	int length = 0, length2 = 0;
	int sumlen = 0, k = 0;
	
	while (destiny[length] != '\0')
	{
		length++;
		sumlen++;
	}
	while (sourc[length2] != '\0')
	{
		length2++;
		sumlen++;
	}
	destiny = _my_realloc(destiny, length, sizeof(char) * sumlen + 1);
	
	for (k = 1; sourc[k] != '\0'; k++)
	{
		destiny[length] = sourc[k];
		length++;
	}
	destiny[length] = '\0';

	return (destiny);
}

/**
 * st_env - setting env
 * @environ: linked list environment vr
 * @nm: environm vr name
 * @direc: directory path)
 * Return: 0 for success
 */
int st_env(list_y **environ, char *nm, char *direc)
{
	int ixe = 0;
	int a = 0;
	char *ct;
	list_y *hdr;

	ct = my_str_dp(nm);
	ct = my_stringcat(ct, "=");
	ct = my_stringcat(ct, direc);
	ixe = my_gtenv(*environ, nm);

	hdr = *environ;
	while (a < ixe)
	{
		hdr = hdr->next;
		a++;
	}
	free(hdr->varib);
	hdr->varib = my_str_dp(ct);
	free(ct);
	return (0);
}
