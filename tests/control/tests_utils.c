/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"
char	**control_position(char **env);

Test(control_position, test1)
{
	char pwd[] = "PWD=/home/marcon/fndfed\0";
	char **env = malloc(sizeof(char *) * 2);

	env[0] = my_strcat(pwd, "\0");
	env[1] = NULL;
	env = control_position(env);
	cr_assert_str_neq(env[0], pwd);
	cr_assert_eq(env[1], NULL);
}

Test(control_position, test2)
{
	char pwd[] = "PWD=/home/marcon\0";
	char **env = malloc(sizeof(char *) * 2);

	env[0] = my_strcat(pwd, "\0");
	env[1] = NULL;
	env = control_position(env);
	cr_assert_str_eq(env[0], pwd);
	cr_assert_eq(env[1], NULL);
}
