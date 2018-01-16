/*
** EPITECH PROJECT, 2017
** test
** File description:
** modifi_position
*/

#include <criterion/criterion.h>
#include "my.h"
char	*modifi_position(char *pwd, char *argu);
#include <stdio.h>

char	*create_pwd(void)
{
	char *pwd = malloc(sizeof(char) * 16);

	pwd[0] = 'P';
	pwd[1] = 'W';
	pwd[2] = 'D';
	pwd[3] = '=';
	pwd[4] = '/';
	pwd[5] = 'h';
	pwd[6] = 'o';
	pwd[7] = 'm';
	pwd[8] = 'e';
	pwd[9] = '/';
	pwd[10] = 'm';
	pwd[11] = 'a';
	pwd[12] = 'r';
	pwd[13] = 'c';
	pwd[14] = 'o';
	pwd[15] = 'n';
	pwd[16] = '\0';
	return (pwd);
}
Test(modifi_position, delete_position)
{
	char *pwd = create_pwd();
	char argu[] = "..\0";
	char *new = modifi_position(pwd, argu);

	cr_assert_str_eq(new, "PWD=/home\0");
}

Test(modifi_position, addposition)
{
	char *pwd = create_pwd();
	char argu[] = "Bureau\0";
	char *new = modifi_position(pwd, argu);

	cr_assert_str_eq(new, "PWD=/home/marcon/Bureau\0");
}

Test(modifi_position, nothing)
{
	char *pwd = create_pwd();
	char argu[] = ".\0";
	char *new = modifi_position(pwd, argu);

	cr_assert_str_eq(new, "PWD=/home/marcon\0");
}
Test(modifi_position, racine)
{
	char *pwd = create_pwd();
	char argu[] = "lib\0";
	char *new = NULL;

	pwd[4] = '\0';
	new = modifi_position(pwd, argu);
	cr_assert_str_eq(new, "PWD=/lib\0");
}
