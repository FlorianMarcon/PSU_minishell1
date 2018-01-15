/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** unset_env
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int	how_long_tab(const char **tab);
int	is_similar(char *src, char *ocu);

char	**prepare_new_env_less_one(char **env)
{
	int size = how_long_tab((const char **)env);
	char **new = NULL;

	if ((new = malloc(sizeof(char *) * size)) == NULL)
		return (NULL);
	new[size - 1] = NULL;
	return (new);
}

char	**unset_env(char **env, char *var)
{
	char **new = prepare_new_env_less_one(env);
	int i = 0;
	int a = 0;

	if (new == NULL)
		return (NULL);
	while (env[i] != NULL) {
		if (is_similar(env[i], var) == 0) {
			new[a] = env[i];
			a++;
		}
		i++;
	}
	new[a] = NULL;
	return (new);
}
