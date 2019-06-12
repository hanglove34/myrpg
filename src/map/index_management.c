/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	add_index_in_ll(ll_t **list, int index)
{
	ll_t *new = malloc(sizeof(*new));

	new->index = index;
	new->next = *list;
	*list = new;
}

void	add_index_used(ll_t **list, int index)
{
	ll_t *tmp = *list;
	int i = 0;

	while (tmp != NULL) {
		if (tmp->index == index)
			return;
		tmp = tmp->next;
		i++;
	}
	add_index_in_ll(list, index);
}
