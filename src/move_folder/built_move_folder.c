/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** built_move_folder
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
int	how_long_tab(const char **tab);
char	**move_folder(char **env, char *argu);

char	**built_move_folder(char **env, char **argu)
{
	if (how_long_tab((const char **)argu) == 1)
		env = move_folder(env, argu[0]);
	else
		my_printf("cd: Too many arguments.\n");
	return (env);
}
