/*
** EPITECH PROJECT, 2017
** test
** File description:
** parsing
*/

#include <criterion/criterion.h>
char	**parsing(char cut, char *str);

Test(parsing, test1)
{
	char str[] = "/home/marcon:/home/bin:last\0";
	char **tab = parsing(':', str);

	cr_assert_str_eq(tab[0], "/home/marcon\0");
	cr_assert_str_eq(tab[1], "/home/bin\0");
	cr_assert_str_eq(tab[2], "last\0");
	cr_assert_eq(tab[3], NULL);
}

Test(parsing, test2)
{
	char *str = NULL;
	char **tab = parsing(':', str);

	cr_assert_eq(tab, NULL);
}

Test(parsing, test3)
{
	char str[] = "/home/marcon/bin:/home/marcon/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin\0";
	char **tab = parsing(':', str);

	cr_assert_str_eq(tab[0], "/home/marcon/bin\0");
	cr_assert_str_eq(tab[1], "/home/marcon/.local/bin");
	cr_assert_str_eq(tab[2], "/usr/local/sbin");
	cr_assert_str_eq(tab[3], "/usr/local/bin");
	cr_assert_str_eq(tab[4], "/usr/sbin");
	cr_assert_str_eq(tab[5], "/usr/bin");
	cr_assert_str_eq(tab[6], "/sbin");
	cr_assert_str_eq(tab[7], "/bin");
	cr_assert_str_eq(tab[8], "/usr/games");
	cr_assert_str_eq(tab[9], "/usr/local/games");
	cr_assert_str_eq(tab[10], "/snap/bin");
	cr_assert_eq(tab[11], NULL);
}
