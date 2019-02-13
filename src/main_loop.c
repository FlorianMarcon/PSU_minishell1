/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** main_loop
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "get_next_line.h"
char	**my_arrcpy(char **arr);
char	**my_str_to_word_array(const char *str);
char	**choice_built(char **env, char **argu);
void	display_path(char **env);
int	how_long_tab(const char **tab);
void	destroy_element_tab(char **tab);
void	execute_program(char **env, char **argu);
char	**control_env(char **envp);

char	**action_argu(char **env, char *str)
{
	char **tmp = NULL;
	char **argu = NULL;

	argu = my_str_to_word_array(str);
	if (argu[0] == NULL) {
		destroy_element_tab(argu);
	}
	else if ((tmp = choice_built(env, argu)) != NULL) {
		env = tmp;
	} else {
		execute_program(env, argu);
		destroy_element_tab(argu);
	}
	return (env);
}
int	main_loop(char **envp)
{
	char *str = NULL;
	char **env = my_arrcpy(envp);

	if (isatty(0))
		display_path(env);
	while ((str = get_next_line(0)) != NULL) {
		env = action_argu(env, str);
		free(str);
		env = control_env(env);
		if (isatty(0))
			display_path(env);
	}
	return (0);
}
