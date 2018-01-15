/*
** EPITECH PROJECT, 2017
** test
** File description:
** destroy_element_tab
*/

#include <criterion/criterion.h>

Test(destroy_element_tab, test1)
{
	char *str = malloc(sizeof(char) * 3);
	char **tab = malloc(sizeof(char *) * 3);

	str[0] = 'a';
	str[1] = 'b';
	str[2] = '\0';
	tab[0] = str;
	tab[1] = str;
	tab[2] = NULL;
}
