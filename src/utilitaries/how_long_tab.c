/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** how_long_tab
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int	how_long_tab(const char **tab)
{
	int size = 0;

	if (tab == NULL)
		return (0);
	while (tab[size] != NULL)
		size++;

	return (size);
}
