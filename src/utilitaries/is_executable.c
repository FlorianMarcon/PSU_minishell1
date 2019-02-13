/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** is_executable
*/

#include "my.h"
#include <unistd.h>

int	is_syntax_executable(char *file)
{
	int i = 2;
	int size = my_strlen(file);

	if (my_strncmp(file, "./", 2) == 0)
		return (1);
	while (i < size) {
		if (file[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
int	is_executable(char *file)
{
	if (access(file, X_OK) == 0 && is_syntax_executable(file))
		return (1);
	else
		return (-1);
}
