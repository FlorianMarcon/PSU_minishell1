/*
** EPITECH PROJECT, 2017
** my_exec
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int	number_word(const char *str)
{
	int i = 0;
	int nb = 0;

	while (str[i] != '\0') {
		if ((str[i] > ' ' && str[i]<= '~') &&
			(i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t'))
			nb++;
		i++;
	}
	return (nb);
}
int	size_until_space(const char *str)
{
	int size = 0;

	while (str[size] != ' ' && str[size] != '\t' && str[size] != '\0')
		size++;
	return (size);
}

char	*stock_in_tab(const char *str)
{
	char *tab = NULL;
	int size = size_until_space(str);

	if ((tab = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	my_strncpy(tab, str, size);
	tab[size] = '\0';
	return (tab);
}
char	**my_str_to_word_array(const char *str)
{
	char **tab = NULL;
	int size = number_word(str);
	int i = 0;
	int a = 0;

	if ((tab = malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (str[i] != '\0') {
		size = size_until_space(&str[i]);
		if (size > 0) {
			tab[a] = stock_in_tab(&str[i]);
			i += size;
			a++;
		} else
			i++;
	}
	tab[a] = NULL;
	return (tab);
}
