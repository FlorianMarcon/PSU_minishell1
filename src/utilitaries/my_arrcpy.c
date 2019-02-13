/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** my_arrcpy
*/

#include "my.h"
#include <stdlib.h>
int	how_long_tab(const char **tab);

char	**my_arrcpy(char **arr)
{
	int size = how_long_tab((char const **)arr);
	char **new = NULL;
	int i = 0;

	if ((new = malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (arr[i] != NULL) {
		size = my_strlen(arr[i]) + 1;
		if ((new[i] = malloc(sizeof(char) * size)) == NULL)
			return (NULL);
		my_strcpy(new[i], arr[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
