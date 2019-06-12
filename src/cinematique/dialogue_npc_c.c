/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

int	slow_dialogue(win_t *win, scene_t scene, cine_t *tmp)
{
	npc_t *npc1;
	npc1 = find_npc(scene.npc, 0);
	if (tmp->pos == 1) {
		tmp->pos++;
		sfClock_restart(npc1->clocks[1].clock);
	}
	while (!scene.npc)
		return (1);
	sfClock *clck = npc1->clocks[1].clock;
	npc1->clocks[1].time = sfClock_getElapsedTime(clck);
	npc1->clocks[1].sec =
	npc1->clocks[1].time.microseconds / 1000000.0;
	if (npc1->clocks[1].sec > 2.0) {
		npc_active(scene.npc, 0, win);
		sfClock_restart(npc1->clocks[1].clock);
		tmp->origin = -1;
		return (1);
	}
	return (0);
}

void	get_entity_dial(win_t *win, scene_t scene, char **cmd,
	cine_t *element)
{
	npc_t *npc1;
	npc_t *npc2;
	if (my_tab_len(cmd) != 4)
		return;
	element->type = my_strdup(cmd[0]);
	element->axe = my_strdup(cmd[1]);
	element->num = my_getnbr(cmd[2]);
	element->origin = 0;
	npc1 = find_npc(scene.npc, 0);
	npc2 = find_npc(scene.npc, element->num);
	free(npc1->tree->main);
	npc1->rect[0] = npc2->rect[0];
	sfSprite_setTextureRect(npc1->dial_spr, npc1->rect[0]);
	npc1->tree->main = my_strdup(cmd[3]);
	cut_text(npc1);
	element->pos = 0;
}
