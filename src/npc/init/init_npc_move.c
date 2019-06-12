/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	move_npc(win_t *win, scene_t scene, npc_t *npc)
{
	sfClock *clck;
	npc_t *npc1;

	if (!scene.npc)
		return;
	clck = scene.npc->clocks[1].clock;
	scene.npc->clocks[1].time = sfClock_getElapsedTime(clck);
	scene.npc->clocks[1].sec =
	scene.npc->clocks[1].time.microseconds / 1000000.0;
	npc1 = find_npc(scene.npc, 1);
	if (npc1 && npc1->state[2] == 1 && scene.npc->clocks[1].sec > 0.1) {
		move_npc_here_left(npc1, 15 * 40 + 2 + scene.map->tr.x, win);
		if (npc1->state[2] == 0 )
			sfSprite_setTextureRect(npc1->spr, npc1->rect[0]);
		sfClock_restart(scene.npc->clocks[1].clock);
	} else if (npc1 && npc1->state[2] == 2 &&
	scene.npc->clocks[1].sec > 0.1) {
		win->state = -1;
		move_npc_here_right(npc1, 16 * 40 + 22 + scene.map->tr.x, win);
		if (npc1->state[2] == 0 )
			sfSprite_setTextureRect(npc1->spr, npc1->rect[0]);
		sfClock_restart(scene.npc->clocks[1].clock);
	}
}

void	new_npc_move(npc_t *new)
{
	int left = new->rect[0].left;
	int top = new->rect[0].top;

	new->move_rect[0][0] = (sfIntRect){left - 78, top, 78, 108};
	new->move_rect[0][1] = (sfIntRect){left, top, 78, 108};
	new->move_rect[0][2] = (sfIntRect){left + 78, top, 78, 108};
	new->move_rect[1][0] = (sfIntRect){left - 78, top + 108, 78, 108};
	new->move_rect[1][1] = (sfIntRect){left, top + 108, 78, 108};
	new->move_rect[1][2] = (sfIntRect){left + 78, top + 108, 78, 108};
	new->move_rect[2][0] = (sfIntRect){left - 78, top + 216, 78, 108};
	new->move_rect[2][1] = (sfIntRect){left, top + 216, 78, 108};
	new->move_rect[2][2] = (sfIntRect){left + 78, top + 216, 78, 108};
	new->move_rect[3][0] = (sfIntRect){left - 78, top + 324, 78, 108};
	new->move_rect[3][1] = (sfIntRect){left, top + 324, 78, 108};
	new->move_rect[3][2] = (sfIntRect){left + 78, top + 324, 78, 108};
	new->clocks[1].clock = sfClock_create();
}
