/*
** EPITECH PROJECT, 2017
** test
** File description:
** controle_env
*/

#include <criterion/criterion.h>
#include "my.h"
#include <unistd.h>
char	**control_path(char **envp);
char	**control_pwd(char **envp);
char	**control_env(char **envp);

Test(control_path, test1)
{
	char *envp[] = {"PWD=\0", NULL};
	char **tmp = control_path(envp);
	char path[] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin\
:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin\0";

	cr_assert_str_eq(envp[0], tmp[0]);
	cr_assert_str_eq(tmp[1], path);
	cr_assert_eq(tmp[2], NULL);
}

Test(control_path_pwd, test2)
{
	char *envp[] = {"PWD=\0", "PATH=\0", NULL};
	char **tmp = control_path(envp);

	cr_assert_str_eq(envp[0], tmp[0]);
	cr_assert_str_eq(tmp[1], envp[1]);
	cr_assert_eq(tmp[2], envp[2]);
	tmp = control_pwd(envp);
	cr_assert_str_eq(envp[0], tmp[0]);
	cr_assert_str_eq(tmp[1], envp[1]);
	cr_assert_eq(tmp[2], envp[2]);
}

Test(control_pwd, test1)
{
	char *envp[] = {"PATH=\0", NULL};
	char **tmp = control_pwd(envp);
	char *pwd = malloc(sizeof(char) * 100);

	getcwd(pwd, 100);
	pwd = my_strcat("PWD=\0", pwd);
	cr_assert_str_eq(envp[0], tmp[0]);
	cr_assert_str_eq(tmp[1], pwd);
	cr_assert_eq(tmp[2], NULL);
}

Test(control_env, tets1)
{
	char *env[] = {"PATH=", "PWD=", NULL};
	char **tmp = control_env(env);
	char *pwd = malloc(sizeof(char) * 100);

	getcwd(pwd, 100);
	pwd = my_strcat("PWD=\0", pwd);
	cr_assert_str_eq(env[0], tmp[0]);
	cr_assert_str_eq(env[1], tmp[1]);
	cr_assert_eq(env[2], tmp[2]);
	env[1] = NULL;
	tmp = control_env(env);
	cr_assert_str_eq(env[0], tmp[0]);
	cr_assert_str_eq(tmp[1], pwd);
	cr_assert_eq(env[2], NULL);
}
