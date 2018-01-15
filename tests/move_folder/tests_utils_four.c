/*
** EPITECH PROJECT, 2017
** test
** File description:
** built_move_folder
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
char	**built_move_folder(char **env, char **argu);

char	**create_tab_test(void)
{
	char **tab = NULL;
	char *str = malloc(sizeof(char) * 2);
	char *str2 = malloc(sizeof(char) * 2);
	char *pwd = malloc(sizeof(char) * 5);

	if ((tab = malloc(sizeof(char *) * 4)) == NULL)
		return (NULL);
	str[0] = 'a';
	str[1] = '\0';
	str2[0] = 'O';
	str2[1] = '\0';
	pwd[0] = 'P';
	pwd[1] = 'W';
	pwd[2] = 'D';
	pwd[3] = '=';
	pwd[4] = '\0';
	tab[0] = str;
	tab[1] = pwd;
	tab[2] = str2;
	tab[3] = NULL;
	return (tab);

}
Test(built_move_folder, test1)
{
	char **env = create_tab_test();
	char **argu = malloc(sizeof(char *) * 3);
	char str[] = "laaaa\0";

	argu[0] = str;
	argu[1] = str;
	argu[2] = NULL;

	cr_redirect_stdout();
	built_move_folder(env, argu);
	cr_assert_stdout_eq_str("cd: Too many arguments.\n");
}

Test(built_move_folder, test2)
{
	char **env = create_tab_test();
	char **argu = malloc(sizeof(char *) * 2);
	char str[] = "/bin/\0";
	char str2[] = "../home\0";

	argu[0] = str;
	argu[1] = NULL;
	env = built_move_folder(env, argu);
	cr_assert_str_eq(env[1], "PWD=/bin");
	argu[0] = str2;
	env = built_move_folder(env, argu);
	cr_assert_str_eq(env[1], "PWD=/home");
}
