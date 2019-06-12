/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** erwann
*/

#include "my.h"

char	*my_revstr(char *str)
{
	int len;
	char save;

	len = my_strlen(str);
	len--;
	for (int i = 0; i <= (len /2); i++) {
		save = str[i];
		str[i] = str[len - i];
		str[len - i] = save;
	}
	return (str);
}

int	my_intlen(int nb)
{
	int i;

	if (nb == 0)
		return (1);
	for (i = 0; nb > 0; i++ )
		nb = nb / 10;
	return (i);
}

char	*my_getstr(int nb)
{
	int len = my_intlen(nb);
	int i = 0;
	char *new_str = malloc((len) + 1 * sizeof(char));
	while (i < len) {
		new_str[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	new_str[i] = '\0';
	new_str = my_revstr(new_str);
	return (new_str);
}
