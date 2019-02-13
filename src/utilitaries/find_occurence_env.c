/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** find_occurence_env
*/

#include "my.h"
#include <stdlib.h>

int	is_similar(char *src, char *ocu)
{
	int i = 0;

	while (ocu[i] != '\0' && src[i] != '\0') {
		if (ocu[i] != src[i])
			return (0);
		i++;
	}
	if (ocu[i] == '\0' && src[i] == '=')
		return (1);
	else
		return (0);
}
char	*find_occurence_env(char **env, char *ocu)
{
	int i = 0;

	while (env[i] != NULL) {
		if (is_similar(env[i], ocu) == 1)
			return (env[i]);
		i++;
	}
	return (NULL);
}
