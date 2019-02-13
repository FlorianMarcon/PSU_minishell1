/*
** EPITECH PROJECT, 2017
** test
** File description:
** set_env
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
char	**built_set_env(char **env, char **argu);

Test(built_set_env, whithout_argument)
{
	char *tab[] =  {"FIRST\0", "SECOND\0", NULL};
	char *argu[] = {NULL};

	cr_redirect_stdout();
	built_set_env(tab, argu);
	cr_assert_stdout_eq_str("FIRST\nSECOND\n\0");
}

Test(built_set_env, whithout_argument2)
{
	char *tab[] =  {"FIRST\0", "SECOND\0", NULL};
	char **argu = NULL;

	cr_redirect_stdout();
	built_set_env(tab, argu);
	cr_assert_stdout_eq_str("FIRST\nSECOND\n\0");
}
