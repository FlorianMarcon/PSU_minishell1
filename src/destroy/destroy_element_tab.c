/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** destroy_element_tab
*/

#include "my.h"
#include <stdlib.h>

void	destroy_element_tab(char **tab)
{
	char **tmp = tab;
	int i = 0;

	while (tmp[i] != NULL) {
		free(tmp[i]);
		i++;
	}
}
