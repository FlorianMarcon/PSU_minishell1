/*
** EPITECH PROJECT, 2017
** how_long_tab
** File description:
** test
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
int	how_long_tab(const char **tab);

Test(how_long_tab, test)
{
	char *str = "la";
	char **tab = malloc(sizeof(char *) * 2);

	tab[0] = str;
	tab[1] = NULL;
	cr_assert_eq(tab[1], NULL);
	cr_assert_eq(how_long_tab((const char **)tab), 1);
}
Test(how_long_tab, test2)
{
	char *str = "la";
	char **tab = malloc(sizeof(char *) * 3);

	tab[0] = str;
	tab[1] = str;
	tab[2] = NULL;
	cr_assert_eq(tab[2], NULL);
	cr_assert_eq(how_long_tab((const char **)tab), 2);
}
Test(how_long_tab, test3)
{
	char *str = "la";
	char **tab = malloc(sizeof(char *) * 5);

	tab[0] = str;
	tab[1] = str;
	tab[2] = str;
	tab[3] = str;
	tab[4] = NULL;
	cr_assert_eq(how_long_tab((const char **)tab), 4);
}
Test(how_long_tab, test4)
{
	char *env[] = {"FIRST=first\0", "SECOND=second\0", NULL};

	cr_assert_eq(how_long_tab((const char **)env), 2);
}

Test(how_long_tab, test5)
{
	char **tab = NULL;

	cr_assert_eq(how_long_tab((const char **)tab), 0);
}
