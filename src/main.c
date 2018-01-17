/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** main
*/

#include "my.h"
#include "header_SHELL.h"
#include <stdlib.h>
#include <stdio.h>
char	**create_env_by_default(void);

int	main(int ac, char **av, char **envp)
{
	if (ac == 1) {
		if (envp == NULL)
			envp = create_env_by_default();
		main_loop(envp);
	} else
		my_printf("%s: Error syntax.", av[1]);
	return (84);
}
