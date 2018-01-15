/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** get_position
*/

#include "my.h"
#include <stdlib.h>
char	*find_occurence_env(char **env, char *ocu);
char	*get_value_var_env(char *var);

char	*get_position(char **env)
{
	char *pwd = find_occurence_env(env, "PWD");

	pwd = get_value_var_env(pwd);
	return (pwd);
}
