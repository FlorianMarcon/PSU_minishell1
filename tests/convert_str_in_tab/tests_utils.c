/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** test convert_str_in_tab
*/

#include <criterion/criterion.h>
#include "my.h"

//char	**my_str_to_word_array(const char *str, int size_str);
int	number_word(char *str, int size);
int	size_until_space(const char *str, int size_str);
char	*stock_in_tab(const char *str, int size_str);

Test(nb_word, test1)
{
	char str[] = "salut tu\tvas  bien?";
	int result = number_word(str, 20);

	cr_assert_eq(result, 4);
}

Test(size_until_space, test1)
{
	char str1[] = "salut oui";
	char str2[] = "salut";
	char str3[] = " la";
	char str4[] = "	la";

	cr_assert_eq(size_until_space(str1, 9), 5);
	cr_assert_eq(size_until_space(str2, 5), 5);
	cr_assert_eq(size_until_space(str3, 3), 0);
	cr_assert_eq(size_until_space(str4, 3), 0);
}

Test(stock_in_tab, test1)
{
	char str[] = "voici le mot";

	cr_assert_str_eq(stock_in_tab(str, 5), "voici");
}
