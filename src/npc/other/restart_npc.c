/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	restart_str_ptr(npc_t *npc)
{
	while (npc->tree && npc->tree->prev) {
		if (npc->tree && npc->tree->offset != 0) {
			npc->tree->main -= npc->tree->offset;
			npc->tree->offset = 0;
		}
		npc->tree = npc->tree->prev;
	}
}

void	restart_npc(npc_t *npc)
{
	npc->active = -npc->active;
	restart_str_ptr(npc);
	while (npc->tree && npc->tree->prev)
		npc->tree = npc->tree->prev;
	npc->cursor.answer = 1;
	npc->cursor.state = 0;
	npc->state[0] = -1;
	sfSprite_setPosition(npc->cursor.spr, npc->cursor.pos[0]);
	npc->txt_i = 0;
}

void	interact_npc(win_t *win, npc_t *npc)
{
	npc_t *tmp = npc;

	while (tmp != NULL && win->state != -2) {
		if (win->heros.pos.x >= tmp->pos.x - 70 &&
		win->heros.pos.x <= tmp->pos.x + 70 &&
		win->heros.pos.y >= tmp->pos.y - 70 &&
		win->heros.pos.y <= tmp->pos.y + 70 &&
		interact_front_npc(tmp, win) == 1 && tmp->active != 1) {
			npc_active(npc, tmp->i, win);
			win->state = -2;
			break;
		}
		tmp = tmp->next;
	}
}
