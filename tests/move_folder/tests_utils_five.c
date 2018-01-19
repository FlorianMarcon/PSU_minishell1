/*
** EPITECH PROJECT, 2017
** move_racine
** File description:
** move_racine
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "my.h"
char	**move_racine(char **env);

Test(move_racine, test1)
{
	char **env = malloc(sizeof(char *) * 3);
	char **tmp = NULL;

	env[0] = my_strcat("PATH=\0", "\0");
	env[1] = my_strcat("PWD=/home/marcon/Bureau\0", "\0");
	env[2] = NULL;
	tmp = move_racine(env);
	cr_assert_str_eq(tmp[0], env[0]);
	cr_assert_str_eq(tmp[1], "PWD=/home/marcon\0");
	cr_assert_eq(tmp[2], NULL);
}
