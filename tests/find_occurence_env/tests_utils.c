/*
** EPITECH PROJECT, 2017
** test
** File description:
** find_occurence_env
*/

#include <criterion/criterion.h>

char	*find_occurence_env(char **env, char *ocu);
int	is_similar(char *src, char *ocu);

Test(find_occurence, test)
{
	char src[] = "FLONFLON=theBest";
	char ocu[] = "FLONFLON";
	char src2[] = "il n'y a pas d'occurence ici";
	char **tab = malloc(sizeof(char *) * 3);

	tab[0] = src2;
	tab[1] = src;
	tab[2] = NULL;
	cr_assert_eq(find_occurence_env(tab, ocu), tab[1]);
	tab[1] = src2;
	cr_assert_eq(find_occurence_env(tab, ocu), NULL);
}

Test(is_similar, test)
{
	char src[] = "FLONFLON=theBest";
	char ocu[] = "FLONFLON";
	char src2[] = "il n'y a pas d'occurence ici";

	cr_assert_eq(is_similar(src, ocu), 1);
	cr_assert_eq(is_similar(src2, ocu), 0);
}

Test(is_similar, test2)
{
	char src[] = "FLONFLON=theBest";
	char ocu[] = "FLONF";

	cr_assert_eq(is_similar(src, ocu), 0);
}
