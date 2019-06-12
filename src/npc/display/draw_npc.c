/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	rotate_npc(npc_t *npc, win_t *win)
{
	sfVector2f pos = {0, 0};

	pos.x = npc->pos.x - win->heros.pos.x;
	pos.y = npc->pos.y - win->heros.pos.y;
	if (ABS(pos.x) > ABS(pos.y)) {
		if (pos.x <= 0)
			sfSprite_setTextureRect(npc->spr, npc->rect[2]);
		else
			sfSprite_setTextureRect(npc->spr, npc->rect[1]);
	} else {
		if (pos.y <= 0)
			sfSprite_setTextureRect(npc->spr, npc->rect[0]);
		else
			sfSprite_setTextureRect(npc->spr, npc->rect[3]);
	}
}

void	draw_behind_npc(win_t *win, npc_t *npc)
{
	npc_t *tmp = npc;

	while (tmp != NULL) {
		if (tmp->pos.y < win->heros.pos.y)
			sfRenderWindow_drawSprite(win->win, tmp->spr, NULL);
		tmp = tmp->next;
	}
}

void	draw_front_npc(win_t *win, npc_t *npc)
{
	npc_t *tmp = npc;

	while (tmp != NULL) {
		if (tmp->pos.y >= win->heros.pos.y)
			sfRenderWindow_drawSprite(win->win, tmp->spr, NULL);
		tmp = tmp->next;
	}
}
