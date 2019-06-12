/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann et les if pas beau = thomas
*/

#include "my.h"

void	move_heros(win_t *win, map_t *map, npc_t *npc, monster_t *monster)
{
	int stop = 0;
	npc_t *tmp = npc;
	for (int i = 0; i < 4; i++) {
		win->heros.origin = (sfIntRect){0, 155, 0, 0};
		win->heros.ver = win->heros.state[7];
		if (cmd_atk(&stop, win->heros.origin, win, monster) == 1)
			break;
		win->heros.state[8] = i;
		choose_direc(win, map, npc, monster);
		if (end_move(win, i, &stop, win->heros.origin) == 1)
			break;
	}
	refresh_map_vtx_arr(map->vtx_arr, map);
	idle_anim(win, stop);
}

void	heros_action_r(win_t *win)
{
	if (win->evt.key.code == sfKeyZ)
		win->heros.state[0] = -1;
	if (win->evt.key.code == sfKeyQ)
		win->heros.state[1] = -1;
	while (win->evt.key.code == sfKeyS) {
		win->heros.state[2] = -1;
		break;
	}
	while (win->evt.key.code == sfKeyD) {
		win->heros.state[3] = -1;
		break;
	}
}

void	other_action(win_t *win)
{
	while (win->evt.key.code == sfKeyD && win->heros.state[3] == -1) {
		if (win->heros.rect.left >= 256 && win->heros.state[5] == -1)
			win->heros.rect.left = 0;
		win->heros.state[3] = 2;
		break;
	}
	if (win->evt.key.code == sfKeySpace && win->heros.state[5] < 0) {
		win->heros.rect.left = 256;
		win->heros.state[5] = 0;
		play_sound(win, 2);
	}
	if (win->evt.key.code == sfKeyE && win->heros.state[6] < 0)
		win->heros.state[6] = 0;
	win->heros.state[4] = -1;
}

void	heros_action_p(win_t *win)
{
	if (win->evt.key.code == sfKeyZ && win->heros.state[0] == -1) {
		if (win->heros.rect.left >= 256 && win->heros.state[5] == -1)
			win->heros.rect.left = 0;
		win->heros.state[0] = 3;
	} if (win->evt.key.code == sfKeyQ && win->heros.state[1] == -1) {
		if (win->heros.rect.left >= 256 && win->heros.state[5] == -1)
			win->heros.rect.left = 0;
		win->heros.state[1] = 1;
	} while (win->evt.key.code == sfKeyS && win->heros.state[2] == -1) {
		if (win->heros.rect.left >= 256 && win->heros.state[5] == -1)
			win->heros.rect.left = 0;
		win->heros.state[2] = 0;
		break;
	}
	other_action(win);
}

void	heros_event_handle(win_t *win)
{
	if (win->evt.type == sfEvtKeyPressed)
		heros_action_p(win);
	if (win->evt.type == sfEvtKeyReleased)
		heros_action_r(win);
}
