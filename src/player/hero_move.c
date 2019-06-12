/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	idle_anim(win_t *win, int stop)
{
	if (stop == 0  && win->heros.state[4] == -1)
		timer(&win->heros, win->heros.state[7], win, stop);
	if (stop == 0) {
		if (win->heros.state[7] == 0)
			win->heros.rect.top = 620;
		anim_player(&win->heros);
	}
}

int	end_move(win_t *win, int i, int *stop, sfIntRect origin)
{
	sfSprite_setPosition(win->heros.spt, win->heros.pos);
	if (win->heros.state[i] != -1 && win->heros.state[5] == -1
	&& win->heros.state[4] == -1) {
		(*stop)++;
		win->heros.state[7] = win->heros.state[i];
		win->heros.rect.top = origin.top;
		move_player(&win->heros);
	}
	if (*stop > 1)
		return (1);
	return (0);
}

void	choose_direc(win_t *win, map_t *map, npc_t *npc, monster_t *monster)
{
	int i = win->heros.state[8];
	switch (win->heros.state[i]) {
		case (0):
			win->heros.origin.top *= win->heros.state[i];
			move_down(win, map, npc, monster);
			break;
		case (1):
			win->heros.origin.top *= win->heros.state[i];
			move_left(win, map, npc, monster);
			break;
		case (2):
			win->heros.origin.top *= win->heros.state[i];
			move_right(win, map, npc, monster);
			break;
		case (3):
			win->heros.origin.top *= win->heros.state[i];
			move_up(win, map, npc, monster);
			break;
	}
}

void	timer(obj_t *heros, int save, win_t *win, int stop)
{
	heros->clock.time = sfClock_getElapsedTime(heros->clock.clock);
	heros->clock.sec = heros->clock.time.microseconds / 1000000.0;
	if (heros->clock.sec > 0.1 && stop == 0) {
		if (save != 0)
			win->heros.rect.top = 620 + (155* save);
		win->heros.rect.left = 384;
		win->heros.state[4] = 0;
		sfClock_restart(heros->clock.clock);
	}
}

void	timer_move(win_t *win, scene_t *scene)
{
	win->heros.clock.time = sfClock_getElapsedTime(
	win->heros.clock.clock);
	win->heros.clock.sec = win->heros.clock.time.microseconds /
	1000000.0;
	if (win->heros.clock.sec > 0.0001)
		move_heros(win, scene[win->scene].map, scene[win->scene].npc,
			scene[win->scene].monster);

}
