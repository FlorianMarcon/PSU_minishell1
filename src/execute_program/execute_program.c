/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** execute_program
*/

#include "my.h"
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
char	*find_occurence_env(char **env, char *ocu);
char	*get_value_var_env(char *var);
char	**parsing(char cut, char *str);
int	program_signal_sigsev(int lock);
int	program_signal_coredump(int lock);
int	exit_status_child(int lock);
int	is_executable(char *file);

int	binaire_is_present(char *path, char *bin)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;
	char *name = NULL;
	char *path_bin = NULL;

	if ((dir = opendir(path)) == NULL)
		return (0);
	while ((file = readdir(dir)) != NULL) {
		name = file->d_name;
		path_bin = my_strcat(path, "/\0");
		path_bin = my_strcat(path_bin, bin);
		if (my_strcmp(name, bin) == 0 && is_executable(path_bin) == 1) {
			closedir(dir);
			return (1);
		}
	}
	return (0);
}
char	*path_for_execute_program(char **env, char **argu)
{
	char *path = find_occurence_env(env, "PATH\0");
	int i = 0;
	char **tab_path = NULL;

	path = get_value_var_env(path);
	tab_path = parsing(':', path);
	while (tab_path[i] != NULL) {
		if (binaire_is_present(tab_path[i], argu[0]) == 1)
			return (tab_path[i]);
		i++;
	}
	return (NULL);
}

void	execution(char **argu, char **env)
{
	int lock;
	pid_t pid;

	pid = fork();
	if (pid == 0) {
		execve(argu[0], argu, env);
	} else {
		waitpid(pid, &lock, 0);
		exit_status_child(lock);
	}
}

void	execute_program(char **env, char **argu)
{
	char *path = path_for_execute_program(env, argu);

	if (path != NULL) {
		path = my_strcat(path, "/\0");
		argu[0] = my_strcat(path, argu[0]);
		execution(argu, env);
	} else if (is_executable(argu[0]) == 1) {
		execution(argu, env);
		my_printf("\n\0");
	} else {
		my_printf("%s: Command not found.\n", argu[0]);
	}
}
