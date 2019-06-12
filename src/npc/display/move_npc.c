/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	move_npc_on_map(npc_t *npc, sfVector2f offset)
{
	npc_t *tmp = npc;

	while (tmp) {
		tmp->pos.x += offset.x;
		tmp->pos.y += offset.y;
		sfSprite_setPosition(tmp->spr, tmp->pos);
		tmp = tmp->next;
	}
}

void	move_npc_here_left(npc_t *npc, int nb, win_t *win)
{
	if (npc->pos.x <= nb) {
		win->state = 0;
		sfSprite_setTextureRect(npc->spr, npc->rect[1]);
		npc->state[2] = 0;
		return;
	}
	npc->pos.x -= 5;
	sfSprite_setPosition(npc->spr, npc->pos);
	sfSprite_setTextureRect(npc->spr, npc->move_rect[1][npc->move[0]]);
	npc->move[0] += (npc->dir[0] * 1);
	if (npc->move[0] == 0 || npc->move[0] == 2)
		npc->dir[0] = -npc->dir[0];
}

void	move_npc_here_right(npc_t *npc, int nb, win_t *win)
{
	if (npc->pos.x >= nb) {
		win->state = 0;
		sfSprite_setTextureRect(npc->spr, npc->rect[2]);
		npc->state[2] = 0;
		return;
	}
	npc->pos.x += 5;
	sfSprite_setPosition(npc->spr, npc->pos);
	sfSprite_setTextureRect(npc->spr, npc->move_rect[2][npc->move[1]]);
	npc->move[1] += (npc->dir[1] * 1);
	if (npc->move[1] == 0 || npc->move[1] == 2)
		npc->dir[1] = -npc->dir[1];
}

void	move_npc_here_up(npc_t *npc, int nb, win_t *win)
{
	if (npc->pos.y <= nb) {
		win->state = 0;
		sfSprite_setTextureRect(npc->spr, npc->rect[3]);
		npc->state[2] = 0;
		return;
	}
	npc->pos.y -= 5;
	sfSprite_setPosition(npc->spr, npc->pos);
	sfSprite_setTextureRect(npc->spr, npc->move_rect[3][npc->move[2]]);
	npc->move[2] += (npc->dir[2] * 1);
	if (npc->move[2] == 0 || npc->move[2] == 2)
		npc->dir[2] = -npc->dir[2];
}

void	move_npc_here_down(npc_t *npc, int nb, win_t *win)
{
	if (npc->pos.y >= nb) {
		win->state = 0;
		sfSprite_setTextureRect(npc->spr, npc->rect[0]);
		npc->state[2] = 0;
		return;
	}
	npc->pos.y += 5;
	sfSprite_setPosition(npc->spr, npc->pos);
	sfSprite_setTextureRect(npc->spr, npc->move_rect[0][npc->move[3]]);
	npc->move[3] += (npc->dir[3] * 1);
	if (npc->move[3] == 0 || npc->move[3] == 2)
		npc->dir[3] = -npc->dir[3];
}
