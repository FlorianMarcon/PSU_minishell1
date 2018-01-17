/*
** EPITECH PROJECT, 2017
** test
** File description:
** get_position
*/

#include <criterion/criterion.h>
#include "my.h"
char	*get_position(char **env);

Test(get_position_pwd, test)
{
	char str[] = "PWD=/home/marcon\0";
	char str2[] = "FLONFLON=\0";
	char **tab = malloc(sizeof(char *) * 3);
	char *result = NULL;

	tab[0] = str2;
	tab[1] = str;
	tab[2] = NULL;
	result = get_position(tab);
	cr_assert_str_eq(result, "/home/marcon\0");
}
Test(get_position, test2)
{
	char str[] = "PWD=\0";
	char str2[] = "FLONFLON=\0";
	char **tab = malloc(sizeof(char *) * 3);
	char *result = NULL;

	tab[0] = str2;
	tab[1] = str;
	tab[2] = NULL;
	result = get_position(tab);
	cr_assert_eq(result, NULL);
}
