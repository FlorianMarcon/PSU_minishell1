/*
** EPITECH PROJECT, 2017
** test
** File description:
** exit_program
*/

#include <criterion/criterion.h>
#include "my.h"
void	exit_program(char **env, char **all, char *argu);

Test(exit, expected_exit, .exit_code = 8)
{
	char *argu = malloc(sizeof(char) * 2);
	char **env = malloc(sizeof(char *) * 2);
	char **all = malloc(sizeof(char *) * 2);
	char *str = malloc(sizeof(char) * 2);

	str[0] = 'a';
	str[1] = '\0';
	argu[0] = '8';
	argu[1] = '\0';
	env[0] = str;
	env[1] = NULL;
	all[0] = argu;
	all[1] = NULL;
	exit_program(env, all, argu);
}
Test(exit, expected_exit2, .exit_code = 0)
{
	char *argu = NULL;
	char **env = malloc(sizeof(char *) * 2);
	char **all = malloc(sizeof(char *) * 2);
	char *str = malloc(sizeof(char) * 2);

	str[0] = 'a';
	str[1] = '\0';
	env[0] = str;
	env[1] = NULL;
	all[0] = argu;
	all[1] = NULL;
	exit_program(env, all, argu);
}
Test(exit, expected_exit3, .exit_code = 42)
{
	char *argu = malloc(sizeof(char) * 3);
	char **env = malloc(sizeof(char *) * 2);
	char **all = malloc(sizeof(char *) * 2);
	char *str = malloc(sizeof(char) * 2);

	str[0] = 'a';
	str[1] = '\0';
	argu[0] = '4';
	argu[1] = '2';
	argu[2] = '\0';
	env[0] = str;
	env[1] = NULL;
	all[0] = argu;
	all[1] = NULL;
	exit_program(env, all, argu);
}
