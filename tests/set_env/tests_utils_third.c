/*
** EPITECH PROJECT, 2017
** test
** File description:
** create_env_by_default
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
char	**create_env_by_default(void);

Test(create_env_by_default, test1)
{
	char **env = create_env_by_default();

	cr_assert_str_eq("PWD=/home/marcon/Repository/SEMESTRE_1/\
PSU_minishell1_2017/tests\0", env[0]);
	cr_assert_eq(env[2], NULL);
}
