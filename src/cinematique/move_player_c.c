/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	reset_value(win_t *win)
{
	win->heros.state[0] = -1;
	win->heros.state[1] = -1;
	win->heros.state[2] = -1;
	win->heros.state[3] = -1;
	win->heros.state[5] = -1;
	win->heros.rect.left = win->heros.rect.width;
}

int	stop_heros(win_t *win, scene_t scene, cine_t *tmp)
{
	if (tmp->axe[0] == 'y') {
		if (tmp->pos == (int)((win->heros.pos.y + 20 - scene.map->tr.y)
		/ SCALE_MAP)) {
			reset_value(win);
			return (0);
		}
	}
	if (tmp->axe[0] == 'x') {
		if (tmp->pos == (int)((win->heros.pos.x + 20 - scene.map->tr.x)
		/ SCALE_MAP)) {
			reset_value(win);
			return (0);
		}
	}
	return (1);
}

void	get_play_y(win_t *win, scene_t scene, cine_t *element)
{
	if (element->axe[0] == 'y') {
		element->origin = (win->heros.pos.y - scene.map->tr.y) / 40;
		if (element->pos < 0)
			win->heros.state[0] = 3;
		if (element->pos > 0)
			win->heros.state[2] = 0;
	}
}

void	get_entity_play(win_t *win, scene_t scene, char **cmd,
	cine_t *element)
{
	if (my_tab_len(cmd) != 3)
		return;
	element->num = 1;
	element->type = my_strdup(cmd[0]);
	element->axe = my_strdup(cmd[1]);
	element->pos = my_getnbr_neg(cmd[2]);
	win->heros.rect.left = 0;
	if (element->axe[0] == 'x') {
		element->origin = (win->heros.pos.x - scene.map->tr.x) / 40;
		if (element->pos < 0)
			win->heros.state[1] = 1;
		if (element->pos > 0)
			win->heros.state[3] = 2;
	}
	get_play_y(win, scene, element);
	win->heros.state[4] = -1;
	win->state = -2;
	element->pos = element->origin + element->pos;
}
