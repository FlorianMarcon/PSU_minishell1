/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** built_set_env
*/

#include "my.h"
char	**set_env(char **env, char **argu);
int	how_long_tab(const char **tab);
char	**display_env(char **env);

char	**built_set_env(char **env, char **argu)
{
	int size = how_long_tab((const char **)argu);

	if (size <= 2 && size > 0)
		env = set_env(env, argu);
	else if (size == 0) {
		display_env(env);
	} else
		my_printf("setenv: Too many arguments\n");
	return (env);
}
