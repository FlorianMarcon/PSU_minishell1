/*
** EPITECH PROJECT, 2017
** test
** File description:
** get_value_var_env
*/

#include <criterion/criterion.h>
#include "my.h"

char	*get_value_var_env(char *var);

Test(get_value_var_env, test1)
{
	char str[] = "FLONFLON=/succeed\0";
	char *var = get_value_var_env(str);

	cr_assert_str_eq(var, "/succeed\0");
}
Test(get_value_var_env, test2)
{
	char str[] = "FLONFLON=\0";
	char *var = get_value_var_env(str);

	cr_assert_eq(var, NULL);
}
Test(get_value_var_env, test3)
{
	char *str = NULL;
	char *var = get_value_var_env(str);

	cr_assert_eq(var, NULL);
}
