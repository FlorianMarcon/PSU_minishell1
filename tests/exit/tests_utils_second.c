/*
** EPITECH PROJECT, 2017
** test
** File description:
** built_exit_program
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
char	**built_exit_program(char **env, char **argu);

Test(built_exit_program, error)
{
	char *env[] = {"salut", "error", NULL};
	char *argu[] = {"8", "9", NULL};
	char final[] = "exit: Expression Syntax.\n";

	cr_redirect_stdout();
	built_exit_program(env, argu);
	cr_assert_stdout_eq_str(final);
}

Test(built_exit_program, height, .exit_code = 8)
{
	char **env = malloc(sizeof(char *) * 1);
	char **argu = malloc(sizeof(char *) * 2);

	env[0] = NULL;
	argu[0] = malloc(sizeof(char) * 2);
	argu[0][0] = '8';
	argu[0][1] = '\0';
	argu[1] = NULL;
	built_exit_program(env, argu);
}
Test(built_exit_program, 0, .exit_code = 0)
{
	char **argu = malloc(sizeof(char *) * 1);
	char **env = malloc(sizeof(char *) * 1);

	env[0] = NULL;
	argu[0] = NULL;
	built_exit_program(env, argu);
}
