/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** exit_program
*/

#include "my.h"
#include <stdlib.h>

void	destroy_element_tab(char **tab);
int	how_long_tab(const char **tab);

void	exit_program(char **env, char **all, char *argu)
{
	int nb = 0;

	if (argu != NULL)
		nb = my_getnbr(argu);
	destroy_element_tab(env);
	destroy_element_tab(all);
	exit(nb);
}

char	**built_exit_program(char **env, char **argu)
{
	if (how_long_tab((const char **)argu) <= 1)
		exit_program(env, argu, argu[0]);
	else
		my_printf("exit: Expression Syntax.\n");
	return (env);
}
