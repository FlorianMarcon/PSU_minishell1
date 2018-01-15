/*
** EPITECH PROJECT, 2017
** test
** File description:
** display_path
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
void	display_path(char **env);

Test(display_path, test)
{
	char *env[] = {"FLONFLON=", "PWD=/bin\0"};

	cr_redirect_stdout();
	display_path(env);
	cr_assert_stdout_eq_str("/bin -> ");
}
