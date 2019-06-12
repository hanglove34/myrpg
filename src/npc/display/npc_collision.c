/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann et les if pas beau = thomas
*/

#include "my.h"

int	interact_front_npc(npc_t *npc, win_t *win)
{
	sfVector2f pos = {0, 0};

	pos.x = win->heros.pos.x - npc->pos.x;
	pos.y = win->heros.pos.y - npc->pos.y;
	if (ABS(pos.x) > ABS(pos.y)) {
		if (pos.x <= 0)
			return ((win->heros.state[7] == 2) ? 1 : 0);
		else
			return ((win->heros.state[7] == 1) ? 1 : 0);
	} else {
		if (pos.y <= 0)
			return ((win->heros.state[7] == 0) ? 1 : 0);
		else
			return ((win->heros.state[7] == 3) ? 1 : 0);
	}
}

int	npc_collision(npc_t *npc, win_t *win, sfVector2f offset)
{
	npc_t *tmp = npc;

	while (tmp) {
		if (tmp->pos.x >= 0 && tmp->pos.x <= 1280 && tmp->pos.y >= 0 &&
		tmp->pos.y <= 720 &&
		(win->heros.pos.x + offset.x >= tmp->pos.x - 40) &&
		(win->heros.pos.x + offset.x <= tmp->pos.x + 40) &&
		(win->heros.pos.y + offset.y >= tmp->pos.y - 25) &&
		(win->heros.pos.y + offset.y <= tmp->pos.y + 15)) {
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
