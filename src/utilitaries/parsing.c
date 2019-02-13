/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** parsing
*/

#include "my.h"
char	**my_str_to_word_array(const char *str);
#include <stdlib.h>
#include <stdio.h>

char	**parsing(char cut, char *str)
{
	int i = 0;
	char **tab = NULL;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0') {
		if (str[i] == cut)
			str[i] = ' ';
		i++;
	}
	tab = my_str_to_word_array(str);
	return (tab);
}
