/*
** EPITECH PROJECT, 2017
** myprintf
** File description:
** printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_printf.h"

int	choice_function(va_list tmp, char *balise)
{
	int i = 0;
	int size = 0;

	while (i != 12) {
		if (balise[0] == tab[i].balise) {
			size = tab[i].fptr(tmp, balise);
			return (size);
		}
		i++;
	}
	return (0);
}
