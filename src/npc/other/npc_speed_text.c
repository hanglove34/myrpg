/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	decrease_text_speed(npc_t *npc)
{
	npc_t *tmp = find_active_npc(npc);

	if (tmp == NULL || tmp->state[3] != 0)
		return;
	tmp->state[0] = -1;
}

void	increase_text_speed(npc_t *npc)
{
	npc_t *tmp = find_active_npc(npc);

	if (tmp == NULL || !tmp->tree->main[tmp->txt_i] || tmp->state[3] != 0)
		return;
	tmp->state[0] = 1;
}
