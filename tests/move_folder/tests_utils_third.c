/*
** EPITECH PROJECT, 2017
** test
** File description:
** move_folder
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include "my.h"
char	**move_folder(char **env, char *argu);

char	**create_tab()
{
	char **tab = NULL;
	char *str = malloc(sizeof(char) * 2);

	if ((tab = malloc(sizeof(char *) * 4)) == NULL)
		return (NULL);
	str[0] = 'a';
	str[1] = '\0';
	tab[0] = str;
	tab[1] = str;
	tab[2] = str;
	tab[3] = NULL;
	return (tab);
}

Test(move_folder, test2)
{
	char **env = create_tab();
	char *pwd = malloc(sizeof(char *) * 5);
	char argu[] = "lib\0";
	char str[] = "a\0";

	pwd[0] = 'P';
	pwd[1] = 'W';
	pwd[2] = 'D';
	pwd[3] = '=';
	pwd[4] = '\0';
	env[1] = pwd;
	env = move_folder(env, argu);
	cr_assert_str_eq(env[0], str);
	cr_assert_str_eq(env[1], "PWD=/lib\0");
	cr_assert_str_eq(env[2], str);
	cr_assert_eq(env[3], NULL);
}

Test(move_folder, test1)
{
	char **env = create_tab();
	char str2[] = "PWD=/lib/systemd\0";
	char argu[] = "../././../\0";
	char str[] = "a\0";

	env[1] = my_strcat(str2, "\0");
	env = move_folder(env, my_strcat(argu, "\0"));
	cr_assert_str_eq(env[0], str);
	cr_assert_str_eq(env[1], "PWD=\0");
	cr_assert_str_eq(env[2], str);
	cr_assert_eq(env[3], NULL);
}

Test(move_folder, test3)
{
	char **env = create_tab();
	char str2[] = "PWD=/home\0";
	char argu[] = "../dfzasqhj\0";
	char str[] = "a\0";

	env[1] = my_strcat(str2, "\0");
	env = move_folder(env, my_strcat(argu, "\0"));
	cr_assert_str_eq(env[0], str);
	cr_assert_str_eq(env[1], "PWD=/home\0");
	cr_assert_str_eq(env[2], str);
	cr_assert_eq(env[3], NULL);
}
