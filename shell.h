#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>

#include <dirent.h>

#include <string.h>

#include <wait.h>

#include <unistd.h>

#include <sys/types.h>

#include <fcntl.h>

#include <sys/wait.h>

#include <stdio.h>

#include <signal.h>

/**
 *struct list - linked list for env var
 *
 *@varib: pointer to envt var string
 *
 *@next: pointing to next node
 */
typedef struct list
{
	char *varib;
	struct list *next;
} list_y;

int st_env(list_y **environ, char *nm, char *direc);
char *con_strncat(char *destiny, char *sourc);
void change_dir(list_y *environ, char *now);
int execute_cd(list_y *environ,
		char *now, char *direct, char *ptr, int number);
int my_changedir(char **pointer, list_y *environ, int number);
list_y *envron_link_lst(char **environ);
int print_envt(char **ptr, list_y *environ);
void com_exit(char **pointer, list_y *environ);
int the_execve(char **ptr, list_y *environ, int number);
int custom_atoi(char *ptr);
void double_ptr_free(char **pointer);
int free_to_exit(char **ptr, list_y *environ, int number, char **mand);
char *my_get_enr(char *pointer, list_y *environ);
size_t _my_get_line(char **pointer);
char *custom_strdp(char *pointer, int nth);
size_t _list_print(list_y *nth);
list_y *end_node_add(list_y **head, char *pointer);
void _linked_list_freed(list_y *thelist);
int _nodeint_delte_at_index(list_y **head, int ixe);
char *_custom_ig(char *pointer);
void _non_interacting(list_y *eniv);
void *_my_realloc(void *pointer, unsigned int prev, unsigned int current);
void control_C(int y);
int repeat_prompt(char **environ);
void _control_D(int a, char *mand, list_y *environ);

char *_space_ig(char *pointer);
int my_bui_lt(char **toek, list_y *environ, int number, char **mand);
char *my_str_dp(char *pointer);
char *my_stringcat(char *second, char *first);
int my_stringcmp(char *string1, char *string2);
char *my_stringcpy(char *second, char *first);
int my_strnlen(char *pointer, int point, char delimeter);
int m_t_sze(char *pointer, char delimet);
char *_delimeter_ig(char *pointer, char delimeta);
char **my_strok(char *pointer, char *delimeta);
char **my_cont_strok(char *pointer, char *delimm);
int re_t_sze(char *pointer, char delim);
char *integ_string(int nm);
int n_length(int nth);

char *my_whic(char *pointer, list_y *environ);
void found_not(char *pointer, int nth, list_y *environ);
void cd_fail(char *pointer, int nt, list_y *environ);
void _wrong_number(char *pointer, int nt, list_y *environ);
int my_set_env(list_y **environ, char **pointer);
int un_env(list_y **environ, char **pointer);
int my_gtenv(list_y *environ, char *pointer);
char *_gt_enve(char *pointer, list_y *environ);

#endif
