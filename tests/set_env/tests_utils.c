/*
** EPITECH PROJECT, 2017
** set_env
** File description:
** tests_utils
*/

#include "my.h"
#include <criterion/criterion.h>
#include <stdlib.h>

char	**prepare_new_env_more_one(char **env);
int	how_long_tab(const char **tab);
char	*new_variable(char **argu);
char	**set_env(char **env, char **argu);

Test(prepare_new_env_more_one, test1)
{
	char str[] = "salut";
	char **tab = malloc(sizeof(char *) * 3);

	tab[0] = str;
	tab[1] = str;
	tab[2] = NULL;
	tab = prepare_new_env_more_one(tab);
	cr_assert_eq(how_long_tab((const char **)tab), 2);
	cr_assert_str_eq(tab[0], str);
	cr_assert_str_eq(tab[1], str);
	cr_assert_eq(tab[3], NULL);
	cr_assert_eq(tab[2], NULL);
}

Test(new_variable, test1)
{
	char str[3];
	char str2[5];
	char **tab = malloc(sizeof(char *) * 3);
	char *var = NULL;

	str[0] = 'F';
	str[1] = 'L';
	str[2] = '\0';

	str2[0] = 'b';
	str2[1] = 'e';
	str2[2] = 's';
	str2[3] = 't';
	str2[4] = '\0';

	tab[0] = str;
	tab[1] = str2;
	tab[2] = NULL;
	var = new_variable(tab);
	cr_assert_str_eq(var, "FL=best");
}

Test(new_variable, test2)
{
	char str[3];
	char **tab = malloc(sizeof(char *) * 2);
	char *var = NULL;

	str[0] = 'F';
	str[1] = 'L';
	str[2] = '\0';

	tab[0] = str;
	tab[1] = NULL;
	var = new_variable(tab);
	cr_assert_str_eq(var, "FL=\0");
}

Test(set_env, test1)
{
	char *env[] = {"FIRST=\0", "SECOND=second\0", NULL};
	char *argu[] = {"FLONFLON\0", "variable\0", NULL};
	char **tmp = NULL;

	tmp = set_env(env, argu);
	cr_assert_eq(how_long_tab((const char **)tmp), 3);
	cr_assert_str_eq(tmp[0], "FIRST=");
	cr_assert_str_eq(tmp[1], "SECOND=second\0");
	cr_assert_neq(tmp[2], NULL);
	cr_assert_str_eq(tmp[2], "FLONFLON=variable\0");
	cr_assert_eq(tmp[3], NULL);
}
