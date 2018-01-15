/*
** EPITECH PROJECT, 2017
** test
** File description:
** display_env
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
char	**display_env(char **env);
char	**built_display_env(char **env, char **argu);

Test(display_env, test1)
{
	char str[] = "salut flonflon";
	char **tab = malloc(sizeof(char *) * 3);
	char **tab2 = NULL;

	tab[0] = str;
	tab[1] = str;
	tab[2] = NULL;
	tab2 = display_env(tab);
	cr_assert_eq(tab, tab2);
	cr_assert_eq(tab2[2], NULL);
	cr_assert_str_eq(tab2[0], str);
	cr_assert_str_eq(tab2[1], str);
}
Test(display_env, test2)
{
	char str[] = "salut flonflon";
	char **tab = malloc(sizeof(char *) * 2);
	char **tab2 = NULL;

	tab[0] = str;
	tab[1] = NULL;
	cr_redirect_stdout();
	tab2 = display_env(tab);
	cr_assert_str_eq(tab2[0], str);
	cr_assert_stdout_eq_str("salut flonflon\n");
}
Test(display_env, test3)
{
	char str[] = "salut flonflon";
	char str2[] = "second oui oui";
	char final[] = "salut flonflon\nsecond oui oui\n";
	char **tab = malloc(sizeof(char *) * 3);

	tab[0] = str;
	tab[1] = str2;
	tab[2] = NULL;
	cr_redirect_stdout();
	display_env(tab);
	cr_assert_stdout_eq_str(final);
}

Test(built_display_env, test3)
{
	char *env[] = {"FLONFLON", "SECOND", NULL};
	char **argu = NULL;
	char final[] = "FLONFLON\nSECOND\n";

	cr_redirect_stdout();
	built_display_env(env, argu);
	cr_assert_stdout_eq_str(final);
}

Test(built_display_env, test4)
{
	char *env[] = {"FLONFLON", "SECOND", NULL};
	char *argu[] = {NULL};
	char final[] = "FLONFLON\nSECOND\n";

	cr_redirect_stdout();
	built_display_env(env, argu);
	cr_assert_stdout_eq_str(final);
}
