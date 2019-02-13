/*
** EPITECH PROJECT, 2017
** test
** File description:
** my_arrcpy
*/

#include <criterion/criterion.h>
char	**my_arrcpy(char **arr);
#include <stdlib.h>

Test(my_arrcpy, test1)
{
	char *tab[] = {"FIRST", "SECOND", NULL};
	char **tmp = my_arrcpy(tab);

	cr_assert_str_eq(tmp[0], tab[0]);
	cr_assert_str_eq(tmp[1], tab[1]);
	cr_assert_eq(tmp[2], tmp[2]);
}

Test(my_arrcpy, test2)
{
	char *tab[] = {NULL};
	char **tmp = my_arrcpy(tab);

	cr_assert_eq(tmp[0], tmp[0]);
}
