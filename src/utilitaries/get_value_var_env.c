/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** get_value_var_env
*/

#include "my.h"
#include <stdlib.h>

char	*get_value_var_env(char *var)
{
	int i = 0;

	if (var == NULL)
		return (NULL);
	while (var[i] != '=' && var[i + 1] != '\0')
		i++;
	if (var[i + 1] == '\0')
		return (NULL);
	return (&var[i + 1]);
}
