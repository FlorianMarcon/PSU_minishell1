/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** built_unset_env
*/

#include "my.h"
#include <stdlib.h>
char	**unset_env(char **env, char *var);

char	**built_unset_env(char **env, char **argu)
{
	int i = 0;

	while (argu[i] != NULL) {
		env = unset_env(env, argu[i]);
		i++;
	}
	return (env);
}
