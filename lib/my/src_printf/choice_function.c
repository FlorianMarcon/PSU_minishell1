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
	int a = 0;
	int size = 0;
	int len = my_strlen(balise);

	while (a != len) {
		i = 0;
		while (i != 12) {
			if (balise[a] == tab[i].balise) {
				size = tab[i].fptr(tmp, balise);
				return (size);
			}
			i++;
		}
		if (balise[a] == tab[i].balise)
			my_putchar('%');
	a++;
	}
	return (0);
}
