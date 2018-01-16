/*
** EPITECH PROJECT, 2017
** test
** File description:
** built_set_env
*/

#include <stdio.h>
#include <criterion/criterion.h>
char	**create_tab_test(void); //tests/move_folder/four
char	**built_set_env(char **env, char **argu);
char	**set_env(char **env, char **argu);

Test(built_set_env, test1)
{
	char **env = create_tab_test();
	char str[] = "PWD\0";
	char str2[] = "chemin\0";
	char **argu = malloc(sizeof(char *) * 3);

	argu[0] = str;
	argu[1] = str2;
	argu[2] = NULL;
	env = built_set_env(env, argu);
	cr_assert_str_eq(env[1], "PWD=chemin\0");
	cr_assert_eq(env[3], NULL);
}

Test(built_set_env, test2)
{
	char *env[] = {"PWD=/home/marcon", "SECOND=second", NULL};
	char *argu[] = {"FLONFLON", "cool", NULL};
	char **tmp = set_env(env, argu);

	cr_assert_str_eq(tmp[2], "FLONFLON=cool\0");
	cr_assert_str_eq(tmp[0], env[0]);
	cr_assert_str_eq(tmp[1], env[1]);
	cr_assert_eq(tmp[3], NULL);
}

Test(built_set_env, test3)
{
	char *env[] = {"PWD=/home/marcon", "SECOND=second", NULL};
	char *argu[] = {"PWD", "cool", NULL};
	char **tmp = set_env(env, argu);

	cr_assert_str_eq(tmp[0], "PWD=cool\0");
	cr_assert_str_eq(tmp[1], env[1]);
	cr_assert_eq(tmp[2], NULL);
}
