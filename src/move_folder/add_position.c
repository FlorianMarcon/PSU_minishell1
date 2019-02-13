/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** add_position
*/

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
char	*get_value_var_env(char *var);

char	*add_position(char *pwd, char *argu)
{
	int size = my_strlen(pwd) + my_strlen(argu) + 3;
	char *new = malloc(sizeof(char) * size);
	char *var = NULL;
	DIR *dir = NULL;

	my_strcpy(new, pwd);
	size = my_strlen(pwd);
	new[size] = '/';
	var = &new[size + 1];
	my_strcpy(var, argu);
	if ((dir = opendir(get_value_var_env(new))) != NULL) {
		closedir(dir);
		chdir(argu);
		return (new);
	} else {
		my_printf("%s: N'est pas un dossier.\n", argu);
		free(new);
		return (NULL);
	}
}
