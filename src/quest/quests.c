/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int	get_quest_nb(char *s, int i)
{
	int nb = 0;

	i += 1;
	while (s[i] && s[i] != 34) {
		nb = (nb * 10) + (s[i] - 48);
		i += 1;
	}
	return (nb);
}

quest_t	*find_quest(quest_t *quest, int nb)
{
	quest_t *tmp = quest;

	while (tmp) {
		if (tmp->nb == nb)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
