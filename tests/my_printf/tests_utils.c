/*
** EPITECH PROJECT, 2017
** test
** File description:
** my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(my_printf, test1)
{
	cr_redirect_stdout();
	my_printf("salut %i\n", 13);
	cr_assert_stdout_eq_str("salut 13\n");
}

Test(my_printf, test2)
{
	cr_redirect_stdout();
	my_printf("salut %s\n", "toi");
	cr_assert_stdout_eq_str("salut toi\n");
}
