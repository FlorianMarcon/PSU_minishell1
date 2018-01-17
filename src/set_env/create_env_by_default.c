/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** create_env_by_default
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char	**create_env_by_default(void)
{
	char **env = NULL;

	if ((env = malloc(sizeof(char *) * 2)) == NULL)
		return (NULL);
	if ((env[0] = malloc(sizeof(char) * 100)) == NULL)
		return (NULL);
	getcwd(env[0], 100);
	chdir(env[0]);
	env[0] = my_strcat("PWD=\0", env[0]);
	env[1] = NULL;
	return (env);
}
