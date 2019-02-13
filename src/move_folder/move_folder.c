/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** move_folder
*/

#include "my.h"
#include <stdlib.h>
char	*find_occurence_env(char **env, char *ocu);
char	*add_position(char *pwd, char *argu);
char	*delete_position(char *pwd);

char	*cut_before_slash(char *str)
{
	int i = 0;

	while (str[i] != '/' && str[i] != '\0')
		i++;
	str[i] = '\0';
	return (str);
}

char	*modifi_position(char *pwd, char *argu)
{
	char *new = NULL;

	if (my_strcmp(argu, "..") == 0)
		new = delete_position(pwd);
	else if (my_strcmp(argu, ".") != 0)
		new = add_position(pwd, argu);
	else
		return (pwd);
	return (new);
}

char	**move_folder(char **env, char *argu)
{
	char *pwd = find_occurence_env(env, "PWD\0");
	char *tmp = NULL;
	int size = my_strlen(argu);
	int i = 0;

	for (i = 0; i < size && pwd != NULL; i++) {
		if (argu[i] != '/') {
			tmp = cut_before_slash(&argu[i]);
			pwd = modifi_position(pwd, tmp);
			i += my_strlen(tmp);
		}
	}
	for (i = 0; env[i] != find_occurence_env(env, "PWD\0") &&
								env[i] != NULL;)
		i++;
	if (env[i] != NULL && pwd != NULL) {
		tmp = env[i];
		env[i] = pwd;
	}
	return (env);
}
