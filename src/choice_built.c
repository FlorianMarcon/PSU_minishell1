/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** choice_function
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
char	**built_move_folder(char **env, char **argu);
char	**built_display_env(char **env, char **argu);
char	**built_set_env(char **env, char **argu);
char	**built_unset_env(char **env, char **argu);
char	**built_exit_program(char **env, char **argu);

typedef struct built_in {
	char *name;
	char ** (*fptr)(char **, char **);
}built_in_t;

const built_in_t list[6] = {{"cd\0", &built_move_folder},
			{"env", &built_display_env},
			{"setenv\0", &built_set_env},
			{"unsetenv", & built_unset_env},
			{"exit\0", &built_exit_program},
			{NULL, NULL}};

char	**choice_built(char **env, char **argu)
{
	int i = 0;

	while (list[i].name != NULL) {
		if (my_strcmp(argu[0], list[i].name) == 0) {
			env = list[i].fptr(env, &argu[1]);
			return (env);
		}
		i++;
	}
	return (NULL);
}
