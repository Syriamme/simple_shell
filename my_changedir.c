#include "shell.h"

/**
 * con_strncat - concatenating two strings
 * @dest: appending string to
 * @src: appended string
 * Return: stringconcatenated
 */

char *con_strncat(char *destiny, char *sourc)
{
	int length = 0, lenght2 = 0;
	int sumlen = 0, int k = 0;
	
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
	destiny = _realloc(destiny, length, sizeof(char) * sum_len + 1);
	
	(for k = 1; src[j] != '\0'; k++)
	{
		destiny[length] = sourc[k];
		len++;
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

	ct = my _strdup(nm);
	ct = my_strcat(ct, "=");
	ct = my_strcat(cat, dir);
	ixe = my_gtenv(*environ, nm);

	hdr = *env;
	while (a < ixe)
	{
		hdr = hdr->next;
		a++;
	}
	free(hdr->varib);
	hdr->varib = my_strdup(ct);
	free(ct);
	return (0);
}

/**
 * change_dir - change to home
 * @environ: updating OLDPWD and PATH
 * @now: bring in current working directotry
 */

void change_dir(list_y *environ, char *now)
{
	char *back = NULL;

	bac = my_gtenv("HOME", environ);
	st_env(&environ, "OLDPWD", now);
	free(back);
	
	if (access(back, F_OK) == 0)
		chdir(back);
	now = NULL;
	now = getcwd(now, 0);
	st_env(&environ, "PWD", now);
	free(now);
	free(back);
}
/**
 * execute_cd - executes chnage directory
 * @environ: bringing linked list to update
 * @now: bringing the pwd
 * @direct: changing path
 * @ptr: error write out
 * @number: line error write out 
 * Return: 2  for fail 1 for success
 */
int execute_cd(list_y *environ, char *now, char *direct, char *ptr, int number)
{
	int a;
	a = 0;

	if (access(direct, F_OK) == 0)
	{
		st_env(&environ, "OLDPWD", now);
		free(now);
		
		chdir(direct);
		now = NULL;
		
		now = getcwd(current, 0);
		st_env(&environ, "PWD", now);
		free(now);
	}
	else
	{
		cd_fail(ptr, number, environ);
		free(now);
		a = 2;
	}
	return (a);
}

/**
 * my_changedir - directory change function
 * @pointer: the user command
 * @environ:  OLDPWD paths and Home paths linked list
 * @number: nth command with error
 * Return: 2 for fail
 */
int my_changedir(char **pointer, list_y *environ, int number)
{
	char *now = NULL;
	char *direct = NULL;
	int exiter = 0;
	
	now = getcwd(now, 0);
	if (pointer[1] != NULL)
	{
		if (pointer[1][0] == '~')
		{
			direct = _gt_enve("HOME", environ);
			direct = con_strncat(direct, pointer[1]);
		}
		else if (pointer[1][0] == '-')
		{
			if (pointer[1][1] == '\0')
				direct = my_gt_enr("OLDPWD", environ);
		}
		else
		{
			if (pointer[1][0] != '/')
			{
				direct = getcwd(direct, 0);
				direct = my_stringcat(direct, "/");
				direct = my_stringcat(direct, pointer[1]);
			}
			else
				direct = my_strdup(pointer[1]);
		}
		exiter = execute_cd(environ, now, direct, pointer[1], number);
		free(direct);
	}

	else
		change_dir(environ, current);
	double_ptr_free(str); /* frees user input */
	return (exit_stat);
}
