/*
** EPITECH PROJECT, 2017
** minishell1
** File description:
** signal_program
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int	program_signal_sigsev(int lock)
{
	if (WTERMSIG(lock) == 1) {
		my_printf("Segmentation fault (SIGSEV)\n");
		return (84);
	}
	else
		return (0);
}

int	program_signal_coredump(int lock)
{
	if (WCOREDUMP(lock) != 0) {
		my_printf("Segmentation fault (core dumped)\n");
		return (84);
	}
	else
		return (0);
}

int	exit_status_child(int lock)
{
	if (WIFSIGNALED(lock) == 1) {
		program_signal_coredump(lock);
//		program_signal_sigsev(lock);
	}
	return (0);
}
