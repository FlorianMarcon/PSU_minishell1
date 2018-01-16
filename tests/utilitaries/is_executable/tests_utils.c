/*
** EPITECH PROJECT, 2017
** test
** File description:
** is_executable
*/

#include <criterion/criterion.h>
int	is_executable(char *file);
int	is_syntax_executable(char *file);

Test(is_executable, test1)
{
	char file[] = "data/a.out\0";
	char file2[] = "saluuuut\0";

	cr_assert_eq(is_executable(file), 1);
	cr_assert_eq(is_executable(file2), -1);
}

Test(is_syntax_executable, test1)
{
	char file[] = "a.out";
	char file2[] = "./a.out";
	char file3[] = "tmp/a.out";

	cr_assert_eq(is_syntax_executable(file), 0);
	cr_assert_eq(is_syntax_executable(file2), 1);
	cr_assert_eq(is_syntax_executable(file3), 1);
}
