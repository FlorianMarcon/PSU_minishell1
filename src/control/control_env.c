/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** controle_env
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>
char	*find_occurence_env(char **env, char *ocu);
char	**set_env(char **env, char **argu);
char	**create_env_by_default(void);

char	**control_path(char **envp)
{
	char *path = find_occurence_env(envp, "PATH\0");
	char **argu = NULL;
	char var[] = "PATH\0";
	char value[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin\
:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin\0";

	if (path != NULL)
		return (envp);
	if ((argu = malloc(sizeof(char *) * 3)) == NULL)
		return (envp);
	argu[0] = my_strcat(var, "\0");
	argu[1] = my_strcat(value, "\0");
	argu[2] = NULL;
	envp = set_env(envp, argu);
	return (envp);
}

char	**control_pwd(char **envp)
{
	char *pwd = find_occurence_env(envp, "PWD\0");
	char **argu = NULL;
	char var[] = "PWD\0";
	char *value = NULL;

	if (pwd != NULL)
		return (envp);
	if ((argu = malloc(sizeof(char *) * 3)) == NULL)
		return (envp);
	if ((value = malloc(sizeof(char) * 100)) == NULL)
		return (envp);
	getcwd(value, 100);
	argu[0] = my_strcat(var, "\0");
	argu[1] = value;
	argu[2] = NULL;
	envp = set_env(envp, argu);
	return (envp);
}
char	**control_env(char **envp)
{
	if (envp == NULL)
		return (create_env_by_default());
	envp = control_path(envp);
	envp = control_pwd(envp);
	return (envp);
}
