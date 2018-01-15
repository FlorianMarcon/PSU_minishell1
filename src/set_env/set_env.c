/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** set_env
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int	how_long_tab(const char **tab);
char	*find_occurence_env(char **env, char *ocu);

char	**prepare_new_env_more_one(char **env)
{
	char **new = NULL;
	int size = how_long_tab((const char **)env) + 2;
	int i = 0;

	if ((new = malloc(sizeof(char *) * (size))) == NULL)
		return (NULL);
	while (env[i] != NULL) {
		new[i] = env[i];
		i++;
	}
	new[i] = NULL;
	new[i + 1] = NULL;
	return (new);
}

char	*new_variable(char **argu)
{
	int size = my_strlen(argu[0]) + my_strlen(argu[1]) + 2;
	char *new = NULL;
	int i = 0;

	if ((new = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	my_strcpy(new, argu[0]);
	size = my_strlen(new);
	new[size] = '=';
	size++;
	while (argu[1] != NULL && argu[1][i] != '\0') {
		new[size] = argu[1][i];
		size++;
		i++;
	}
	new[size] = '\0';
	return (new);
}

char	**set_env(char **env, char **argu)
{
	int i = 0;
	char *var = new_variable(argu);
	char *tmp = find_occurence_env(env, argu[0]);

	i = 0;
	if (tmp != NULL) {
		while (env[i] != tmp)
			i++;
	} else {
		env = prepare_new_env_more_one(env);
		while (env[i] != NULL) {
			i++;
		}
	}
	env[i] = var;
	return (env);
}
