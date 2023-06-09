#include "shell.h"

/**
 *change_dir - change to home
 *@environ: updating OLDPWD and PATH
 *@now: bring in current working directotry
 */

void change_dir(list_y *environ, char *now)
{
	char *back = NULL;

	back = my_get_enr("HOME", environ);

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
 *execute_cd - executes chnage directory
 *@environ: bringing linked list to update
 *@now: bringing the pwd
 *@direct: changing path
 *@ptr: error write out
 *@number: line error write out
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
		now = getcwd(now, 0);
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
			direct = my_get_enr("HOME", environ);
			direct = con_strncat(direct, pointer[1]);
		}
		else if (pointer[1][0] == '-')
		{
			if (pointer[1][1] == '\0')
				direct = my_get_enr("OLDPWD", environ);
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
				direct = my_str_dp(pointer[1]);
		}
		exiter = execute_cd(environ, now, direct, pointer[1], number);
		free(direct);
	}

	else
		change_dir(environ, now);
	double_ptr_free(pointer);
	return (exiter);
}
