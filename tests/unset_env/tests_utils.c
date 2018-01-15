/*
** EPITECH PROJECT, 2017
** unset_env
** File description:
** test
*/

#include "my.h"
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>

int	find_occurence_env(char *src, char *ocu);
char	**prepare_new_env_less_one(char **env);
int	how_long_tab(const char **tab);
char	**unset_env(char **env, char *var);
char	**built_unset_env(char **env, char **argu);

/*
Test(prepare_new_env_less_one, test)
{
	char str[] = "sentence";
	char **tab = malloc(sizeof(char *) * 4);
	char **expected = malloc(sizeof(char *) * 3);

	expected[2] = NULL;
	tab[0] = str;
	tab[1] = str;
	tab[2] = str;
	tab[3] = NULL;ma
	tab = prepare_new_env_less_one(tab);
	//cr_assert_str_empty(tab);
}*/

Test(unset_env, test)
{
	char str1[] = "FLONFLON=theBest";
	char str2[] = "OUI=je me la pete";
	char **env = malloc(sizeof(char *) * 3);
	char *var = "FLONFLON";

	env[0] = str1;
	env[1] = str2;
	env[2] = NULL;
	env = unset_env(env, var);
	cr_assert_str_eq(env[0], str2);
	cr_assert_eq(how_long_tab((const char **)env), 1);
	cr_assert_eq(env[1], NULL);
}

Test(built_unset_env, test1)
{
	char *env[] = {"FLONFLON=ouimonsieur", "SECOND=", "THIRD=", NULL};
	char *argu[] = {"FLONFLON", NULL};
	char **tmp = built_unset_env(env, argu);

	cr_assert_str_neq(tmp[0], "FLONFLON=ouimonsieur");
	cr_assert_str_eq(tmp[0], "SECOND=");
	cr_assert_str_eq(tmp[1], "THIRD=");
	cr_assert_eq(tmp[2], NULL);
}

Test(built_unset_env, test2)
{
	char *env[] = {"FLONFLON=ouimonsieur", "SECOND=", "THIRD=", NULL};
	char *argu[] = {"FLONFLON", "SECOND", NULL};
	char **tmp = built_unset_env(env, argu);

	cr_assert_str_neq(tmp[0], "FLONFLON=ouimonsieur");
	cr_assert_str_neq(tmp[0], "SECOND=");
	cr_assert_str_eq(tmp[0], "THIRD=");
	cr_assert_eq(tmp[1], NULL);
}
