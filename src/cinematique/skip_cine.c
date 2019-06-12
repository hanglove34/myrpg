/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	skip_cine(win_t *win, scene_t *scene)
{
	int n = 0;
	if (win->num_cine == 0)
		return;
	for (cine_t *p_temp = win->cine; p_temp != NULL;
	p_temp = p_temp->next) {
		if (p_temp->num != -1)
			n = skip_entity(win, scene, p_temp);
	}
	get_cmd(win, *scene);
}

void	skyp_npc(win_t *win, scene_t scene, cine_t *tmp)
{
	npc_t *npc = find_npc(scene.npc, tmp->num);
	if (tmp->axe[0] == 'x')
		npc->pos.x = (tmp->pos * 40 + 22 + scene.map->tr.x);
	if (tmp->axe[0] == 'y')
		npc->pos.y = (tmp->pos * 40 + 22 + scene.map->tr.y);
	sfSprite_setPosition(npc->spr, npc->pos);
}

void	skyp_player(win_t *win, scene_t *scene, cine_t *tmp)
{
	if (tmp->axe[0] == 'x') {
		if (move_type_x(win , scene->map, 1))
			win->heros.pos.x = (tmp->pos * 40 + scene->map->tr.x);
		else
			scene->map->tr.x = (-1 * (tmp->pos * 40));
	}
	if (tmp->axe[0] == 'y') {
		if (move_type_y(win , scene->map, 1))
			win->heros.pos.y = (tmp->pos * 40 + scene->map->tr.y);
		else
			scene->map->tr.y = (-1 * (tmp->pos * 40));
	}
	sfSprite_setPosition(win->heros.spt, win->heros.pos);
}

int	skip_entity(win_t *win, scene_t *scene, cine_t *tmp)
{
	npc_t *npc1;
	if (my_strcmp(tmp->type, "P") == 0) {
		skyp_npc(win, *scene, tmp);
	} if (my_strcmp(tmp->type, "J") == 0) {
		while (stop_heros(win, *scene, tmp) != 0)
			move_heros(win, scene->map, scene->npc, scene->monster);
	} while (my_strcmp(tmp->type, "D") == 0) {
		npc_active((*scene).npc, 0, win);
		break;
	}
	return (0);
}
