/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** built_move_folder
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	how_long_tab(const char **tab);
char	**move_folder(char **env, char *argu);
char	**move_racine(char **env);
char	*get_value_var_env(char *var);
char	*find_occurence_env(char **env, char *ocu);

char	**built_move_folder(char **env, char **argu)
{
	char *pwd = NULL;

	if (how_long_tab((const char **)argu) == 1)
		env = move_folder(env, argu[0]);
	else if (argu == NULL || argu[0] == NULL)
		env = move_racine(env);
	else
		my_printf("cd: Too many arguments.\n");
	pwd = find_occurence_env(env, "PWD\0");
	pwd = get_value_var_env(pwd);
	printf("built_move_folder %s\n", pwd);
	chdir(pwd);
	return (env);
}
