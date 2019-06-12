/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	move_npc_du(win_t *win, scene_t scene, int move, npc_t *npc1)
{
	if (npc1 && npc1->state[2] == 3 && npc1->clocks[1].sec > 0.08) {
		move_npc_here_down(npc1, move * 40 + 22 + scene.map->tr.y, win);
		sfClock_restart(npc1->clocks[1].clock);
	} else if (npc1 && npc1->state[2] == 4 &&
	npc1->clocks[1].sec > 0.08) {
		move_npc_here_up(npc1, move * 40 + 22 +scene.map->tr.y, win);
		sfClock_restart(npc1->clocks[1].clock);
	}
}

void	move_n_npc(win_t *win, scene_t scene, int move, int num_npc)
{
	sfClock *clck;
	npc_t *npc1;

	while (!scene.npc)
		return;
	npc1 = find_npc(scene.npc, num_npc);
	clck = npc1->clocks[1].clock;
	npc1->clocks[1].time = sfClock_getElapsedTime(clck);
	npc1->clocks[1].sec =
	npc1->clocks[1].time.microseconds / 1000000.0;
	if (npc1 && npc1->state[2] == 1 && npc1->clocks[1].sec > 0.08) {
		move_npc_here_left(npc1, move * 40 + 22 + scene.map->tr.x, win);
		sfClock_restart(npc1->clocks[1].clock);
	} else if (npc1 && npc1->state[2] == 2 &&
	npc1->clocks[1].sec > 0.08) {
		move_npc_here_right(npc1, move * 40 + 22 +scene.map->tr.x, win);
		sfClock_restart(npc1->clocks[1].clock);
	}
	move_npc_du(win, scene, move, npc1);
	win->state = -2;
}

void	get_entity_y(win_t *win, scene_t scene, cine_t *tmp, npc_t *npc1)
{
	if (tmp->axe[0] == 'y') {
		tmp->origin = (npc1->pos.y - scene.map->tr.y - 22) / 40;
		if (tmp->pos < 0)
			npc1->state[2] = 4;
		if (tmp->pos > 0)
			npc1->state[2] = 3;
	}
}

void	get_entity_npc(win_t *win, scene_t scene, char **cmd, cine_t *tmp)
{
	npc_t *npc1;
	if (my_tab_len(cmd) != 4)
		return;
	tmp->num = my_getnbr(cmd[1]);
	tmp->type = my_strdup(cmd[0]);
	tmp->axe = my_strdup(cmd[2]);
	tmp->pos = my_getnbr_neg(cmd[3]);
	npc1 = find_npc(scene.npc, tmp->num);
	if (tmp->axe[0] == 'x') {
		tmp->origin = (npc1->pos.x - scene.map->tr.x - 22) / 40;
		if (tmp->pos < 0)
			npc1->state[2] = 1;
		if (tmp->pos > 0)
			npc1->state[2] = 2;
	}
	get_entity_y(win, scene, tmp, npc1);
	tmp->pos = tmp->origin + tmp->pos;
}
