/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** display_env
*/

#include "my.h"
#include <stdlib.h>

char	**display_env(char **env)
{
	int i = 0;

	while (env[i] != NULL) {
		my_printf("%s\n", env[i]);
		i++;
	}
	return (env);
}

char	**built_display_env(char **env, char **argu)
{
	if (argu == NULL || argu[0] == NULL)
		display_env(env);
	return (env);
}
