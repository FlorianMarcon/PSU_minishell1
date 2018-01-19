/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** delete_position
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

char	*delete_position(char *pwd)
{
	int size = my_strlen(pwd);;
	int i = size;
	char *new = NULL;

	if ((new = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	my_strcpy(new, pwd);
	while (new[i] != '/' && new[i - 1] != '=')
		i--;
	new[i] = '\0';
	chdir("..");
	return (new);
}
