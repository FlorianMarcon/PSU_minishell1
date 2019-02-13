/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** control_position
*/

#include "my.h"
#include <sys/types.h>
#include <dirent.h>
char	*find_occurence_env(char **env, char *ocu);
char	*get_value_var_env(char *var);
char	*delete_position(char *pwd);

char	**control_position(char **env)
{
	char *pwd = find_occurence_env(env, "PWD\0");
	DIR *dir = NULL;
	int i = 0;
	char *tmp = NULL;

	tmp = get_value_var_env(pwd);
	while ((dir = opendir(tmp)) == NULL) {
		tmp = delete_position(tmp);
	}
	while (env[i] != pwd)
		i++;
	if (tmp != NULL) {
		tmp = my_strcat("PWD=\0", tmp);
		env[i] = tmp;
	}
	return (env);
}
