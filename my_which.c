#include "shell.h"

/**
 * _my_whic - match PATH directory to command
 * @pointer: user commmand
 * @environ: the envt var
 * Return: command copy
 */
char *my_whic(char *pointer, list_y *environ)
{
	char *cpycat = NULL;
	char *path;
	char **token;
	int j = 0;

	path = my_get_enr("PATH", environ);
	
	token = my_cont_strok(path, ":");
	
	free(path);

	for (j = 0; (token[j] != NULL); j++)
	{
		if (token[j][0] == '\0')
		{
			cpycat = getcwd(cpycat, 0);
		}
		else
			cpycat =my_str_dp(token[j]);
		cpycat = my_stringcat(cpycat, "/");
		cpycat = my_stringcat(cpycat, pointer);
		
		if (access(cpycat, F_OK) == 0)
		{
			double_ptr_free(token);
			return (cpycat);
		}
		free(cpycat);
	}
	double_ptr_free(token);
	return (pointer);
}
