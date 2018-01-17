/*
** EPITECH PROJECT, 2017
** minishell
** File description:
** garbage_collector
*/

#include "my.h"
#include <stdlib.h>
static linked_list_t garbage = {NULL, NULL};

void	add_in_garbage(void *data)
{
	create_node(&garbage, data);
}

void	free_garbage(void)
{
	linked_list_t *tmp = &garbage;
	linked_list_t *last = get_lastnode(&garbage);

	while (last != &garbage) {
		while (tmp->next != last)
			tmp = tmp->next;
		free(last->data);
		free(last);
		tmp->next = NULL;
		tmp = &garbage;
	}
}
