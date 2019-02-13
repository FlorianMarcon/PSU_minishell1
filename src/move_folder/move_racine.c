/*
** EPITECH PROJECT, 2017
** move_racine
** File description:
** move_racine
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
char	*find_occurence_env(char **env, char *ocu);
char	*get_value_var_env(char *var);

char	**move_racine(char **env)
{
	char *pwd = find_occurence_env(env, "PWD");
	char str[] = "PWD=/home/marcon\0";

	my_strcpy(pwd, str);
	chdir("/home/marcon");
	return (env);
}
