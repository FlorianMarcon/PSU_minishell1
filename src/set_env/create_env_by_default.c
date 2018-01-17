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
	char path[] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin\
			:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin\0";

	if ((env = malloc(sizeof(char *) * 3)) == NULL)
		return (NULL);
	if ((env[0] = malloc(sizeof(char) * 100)) == NULL)
		return (NULL);
	getcwd(env[0], 100);
	chdir(env[0]);
	env[0] = my_strcat("PWD=\0", env[0]);
	env[1] = my_strcat(path, "\0");
	env[2] = NULL;
	return (env);
}
