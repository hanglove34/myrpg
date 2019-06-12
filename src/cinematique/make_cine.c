/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	timer_cine(win_t *win, scene_t scene, cine_t *tmp)
{
	win->clock.time = sfClock_getElapsedTime(win->clock.clock);
	win->clock.sec = win->clock.time.microseconds / 1000000.0;
	if (win->clock.sec > 0.032) {
		move_heros(win, scene.map, scene.npc, scene.monster);
		sfClock_restart(win->clock.clock);
	}
}

void	parcour_entity(win_t *win, scene_t scene)
{
	int n = 0;
	if (win->num_cine == 0)
		return;
	int stop = 0;
	cine_t *p_temp = win->cine;
	while (p_temp != NULL) {
		if (p_temp->num != -1)
			n = move_entity_c(win, scene, p_temp);
		if (n == 1)
			stop = 1;
		p_temp = p_temp->next;
	}
	if (stop == 0)
		get_cmd(win, scene);
}

int	do_dialogue(win_t *win, scene_t scene, cine_t *tmp, npc_t *npc1)
{
	npc1 = find_npc(scene.npc, 0);
	if (tmp->pos == 0) {
		npc_active(scene.npc, 0, win);
		win->cine->pos++;
		sfClock_restart(npc1->clocks[1].clock);
		win->state = -2;
	} if (npc1->tree->main[npc1->txt_i] == '\0')
		if (slow_dialogue(win, scene, tmp) == 1)
			return (0);
	return (1);
}

int	move_entity_c(win_t *win, scene_t scene, cine_t *tmp)
{
	npc_t *npc1;
	if (my_strcmp(tmp->type, "P") == 0) {
		npc1 = find_npc(scene.npc, tmp->num);
		if (npc1->state[2] == 0)
			return (0);
		move_n_npc(win, scene, tmp->pos, tmp->num);
	} if (my_strcmp(tmp->type, "J") == 0) {
		if (stop_heros(win, scene, tmp) == 0)
			return (0);
		timer_cine(win, scene, tmp);
	} while (my_strcmp(tmp->type, "D") == 0) {
		if (do_dialogue(win, scene, tmp, npc1) == 0)
			return (0);
		break;
	}
	return (1);
}
