/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	get_time_pict_clock(npc_t *tmp)
{
	tmp->clocks[2].time = sfClock_getElapsedTime(tmp->clocks[2].clock);
	tmp->clocks[2].sec = tmp->clocks[2].time.microseconds / 1000000.0;
}

void	set_npc_pict(npc_t *npc, win_t *win)
{
	sfIntRect null_rect = {0, 0, 0, 0};
	tree_t *tmp = npc->tree;

	sfSprite_setTextureRect(npc->pict, null_rect);
	if (npc->type == MERCH)
		sfSprite_setTextureRect(npc->pict, npc->pict_rect[2]);
	if (tmp->prev)
		tmp = tmp->prev;
	while (tmp->quest && tmp->quest->type == 1) {
		sfSprite_setTextureRect(npc->pict, npc->pict_rect[0]);
		break;
	}
	if (tmp->quest && tmp->quest->type == 3 &&
	find_quest(win->quest, tmp->quest->quest_nb)->state == 1)
		sfSprite_setTextureRect(npc->pict, npc->pict_rect[1]);
	while (npc->type == SAVE) {
		sfSprite_setTextureRect(npc->pict, npc->pict_rect[3]);
		break;
	}
}

void	move_npc_pict(npc_t *tmp)
{
	if (tmp->clocks[2].sec > 0.06) {
		sfClock_restart(tmp->clocks[2].clock);
		tmp->pict_move[0] += tmp->pict_move[1] * 1;
		if (tmp->pict_move[0] == 0 || tmp->pict_move[0] == 15)
			tmp->pict_move[1] = -tmp->pict_move[1];
	}
}

void	display_npc_pict(npc_t *npc, win_t *win)
{
	npc_t *tmp = npc;

	while (tmp) {
		get_time_pict_clock(tmp);
		set_npc_pict(tmp, win);
		move_npc_pict(tmp);
		sfSprite_setPosition(tmp->pict,
		(sfVector2f){tmp->pos.x, tmp->pos.y - 135 + tmp->pict_move[0]});
		sfRenderWindow_drawSprite(win->win, tmp->pict, NULL);
		tmp = tmp->next;
	}
}
