/*
** EPITECH PROJECT, 2017
** test
** File description:
** execute_program
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
int	binaire_is_present(char *path, char *binaire);
char	*path_for_execute_program(char **env, char **argu);
void	execute_program(char **env, char **argu);

Test(binaire_is_present, test1)
{
	char path[] = "/bin/\0";
	char binaire[] = "ls\0";

	cr_assert_eq(binaire_is_present(path, binaire), 1);
	cr_assert_neq(binaire_is_present(path, binaire), 0);
}

Test(binaire_is_present, test2)
{
	char path[] = "/bin/\0";
	char binaire[] = "adsveugzeifi\0";

	cr_assert_eq(binaire_is_present(path, binaire), 0);
	cr_assert_neq(binaire_is_present(path, binaire), 1);
}

Test(path_for_execute_program, test1)
{
	char *str = malloc(sizeof(char) * 147);
	str = my_strcpy(str, "PATH=/home/marcon/bin:/home/marcon/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin\0");
	char *env[] = {"PWD=/home/marcon\0", str, NULL};
	char *argu[] = {"ls\0", "other argu inutile", NULL};

	char *path = path_for_execute_program(env, argu);
	cr_assert_neq(path, NULL);
	cr_assert_str_eq(path, "/bin\0");
}

Test(execute_program, test1)
{
	char *str = malloc(sizeof(char) * 147);
	str = my_strcpy(str, "PATH=/home/marcon/bin:/home/marcon/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin\0");
	char *env[] = {"PWD=\0", str, NULL};
	char *argu[] = {"echo", "salut", NULL};

	cr_redirect_stdout();
	execute_program(env, argu);
	cr_assert_stdout_eq_str("salut\n");
}
