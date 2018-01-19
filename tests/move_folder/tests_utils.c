/*
** EPITECH PROJECT, 2017
** test
** File description:
** move_folder
*/

#include "my.h"
#include <criterion/criterion.h>

char	*cut_before_slash(char *str);
char	*delete_position(char *pwd);
char	*add_position(char *pwd, char *argu);

Test(cut_before_slash, test)
{
	char str[] = "home/marcon";
	char str2[] = "marcon\0";
	char str3[] = "\0";
	char *var = cut_before_slash(str);

	cr_assert_str_eq(var, "home");
	var = cut_before_slash(str2);
	cr_assert_str_eq(var, "marcon");
	var = cut_before_slash(str3);
	cr_assert_str_eq(var, "\0");
}

Test(delete_position, test)
{
	char str[] = "FLONFLON=/salut/ca/va\0";
	char result[] = "FLONFLON=/salut/ca\0";
	char str2[] = "FLONFLON=\0";

	cr_assert_str_eq(delete_position(str), result);
	cr_assert_str_eq(delete_position(str2), str2);
}
Test(add_position, test1)
{
	char *pwd = malloc(sizeof(char) * 5);
	char argu[] = "home\0";
	char *new = NULL;

	pwd[0] = 'P';
	pwd[1] = 'W';
	pwd[2] = 'D';
	pwd[3] = '=';
	pwd[4] = '\0';
	new = add_position(pwd, argu);
	cr_assert_str_eq(new, "PWD=/home\0");
}

Test(add_position, test2)
{
	char *pwd = malloc(sizeof(char) * 5);
	char argu[] = "bar_argu\0";
	char *new = NULL;

	pwd[0] = 'P';
	pwd[1] = 'W';
	pwd[2] = 'D';
	pwd[3] = '=';
	pwd[4] = '\0';
	new = add_position(pwd, argu);
	cr_assert_eq(new, NULL);
}
