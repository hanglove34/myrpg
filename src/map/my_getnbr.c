/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

int	my_getnbr(char *test)
{
	int nb = 0;

	if (test == NULL)
		return (-1);
	while (*test <= '9' && *test >= '0') {
		nb += *test - '0';
		if (*(test + 1) <= '9' && *(test + 1) >= '0')
			nb *= 10;
		test++;
	}
	if (*test != '\0')
		return (-1);
	return (nb);
}
