/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** delete_position
*/

#include "my.h"
#include <unistd.h>

char	*delete_position(char *pwd)
{
	int i = my_strlen(pwd);

	while (pwd[i] != '/' && pwd[i - 1] != '=')
		i--;
	pwd[i] = '\0';
	chdir("..");
	return (pwd);
}
