/*
** EPITECH PROJECT, 2017
** test
** File description:
** choice_built
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
char	**choice_built(char **env, char **argu);
char	**create_tab_test(void);
char	**my_arrcpy(char **arr);
void	destroy_element_tab(char **tab);

Test(choice_built, display_env)
{
	char *var[] = {"FLONFLON", "YES", NULL};
	char **env = my_arrcpy(var);
	char **argu = my_arrcpy(var);
	char **tmp = NULL;

	argu[0] = my_strcat("env\0", "\0");
	argu[1] = NULL;
	cr_redirect_stdout();
	tmp = choice_built(env, argu);
	cr_assert_stdout_eq_str("FLONFLON\nYES\n");
	cr_assert_str_eq(tmp[0], env[0]);
	cr_assert_str_eq(tmp[1], env[1]);
	cr_assert_eq(tmp[2], env[2]);
}

Test(choice_built, move)
{
	char **env = create_tab_test();
	char **argu = malloc(sizeof(char *) * 3);

	argu[0] = malloc(sizeof(char) * 3);
	argu[0][0] = 'c';
	argu[0][1] = 'd';
	argu[0][2] = '\0';
	argu[1] = malloc(sizeof(char) * 5);
	argu[1][0] = 'h';
	argu[1][1] = 'o';
	argu[1][2] = 'm';
	argu[1][3] = 'e';
	argu[1][4] = '\0';
	argu[2] = NULL;
	env = choice_built(env, argu);
	cr_assert_str_eq(env[1], "PWD=/home\0");
	cr_assert_neq(env[1], NULL);
}

Test(choice_built, setenv)
{
	char **env = create_tab_test();
	char *argup[] = {"setenv\0", "NEW\0", "new\0", NULL};
	char **argu = my_arrcpy(argup);
	char **tmp = choice_built(env, argu);

	cr_assert_str_eq(tmp[0], env[0]);
	cr_assert_str_eq(tmp[1], env[1]);
	cr_assert_str_eq(tmp[2], env[2]);
	cr_assert_str_eq(tmp[3], "NEW=new\0");
	cr_assert_eq(tmp[4], NULL);
	free(env);
	free(argu);
	free(tmp);
}

Test(choice_built, unsetenv)
{
	char **env = create_tab_test();
	char *argup[] = {"unsetenv\0", "PWD\0", NULL};
	char **argu = my_arrcpy(argup);
	char **tmp = choice_built(env, argu);

	cr_assert_str_eq(tmp[0], env[0]);
	cr_assert_str_eq(tmp[1], env[2]);
	cr_assert_eq(tmp[2], NULL);
	destroy_element_tab(env);
	destroy_element_tab(argu);
}

Test(choice_built, exit, .exit_code = 0)
{
	char **env = create_tab_test();
	char *argup[] = {"exit\0", NULL};
	char **argu = my_arrcpy(argup);

	choice_built(env, argu);
	destroy_element_tab(env);
	destroy_element_tab(argu);
}
