/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** display_path
*/

#include "my.h"
char	*get_position(char **env);

void	display_path(char **env)
{
	char *tmp = get_position(env);

	my_printf("%s -> \0", tmp);
}
