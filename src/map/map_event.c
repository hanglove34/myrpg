/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

void	map_key_pressed(win_t *win, scene_t *scene)
{
	switch (win->evt.key.code) {
		case (sfKeyC):
			if (win->scene == 0) {
				win->scene = 1;
				scene[win->scene].map->tr = (sfVector2f){0, 0};
				win->heros.pos = (sfVector2f){WIDTH / 2 -
				70, HEIGHT / 2 - 30};
			}
			else {
				win->scene = 0;
				scene[win->scene].map->tr = (sfVector2f){0,
				-159};
				win->heros.pos = (sfVector2f){WIDTH / 2, 720};
			}
			break;
		default:
			break;
	}
}

void	my_switch_scene(int nb, sfFloatRect rect,
	scene_t *scene, win_t *win)
{
	if (scene[nb].init == 0) {
		init_targeted_scenes("other/scene", nb, win, scene);
	}
	win->scene = nb;
	sfVector2f tr = {rect.left, rect.top};
	sfVector2f pos = {rect.width, rect.height};
	scene[win->scene].map->tr = tr;
	win->heros.pos = pos;
}

void	switch_scene(win_t *win, scene_t *scene, int nb)
{
	scene[win->scene].map->event = -42;

	if (scene[nb / 10].tp == 0)
		return;
	if (nb < 0 || nb >= 150)
		return;
	reset_player_move(win);
	if (nb < 90)
		switch_scene_act_one(win, scene, nb);
	else if (nb < 150)
		switch_act_two_part_one(win, scene, nb);
}

void	map_events(win_t *win, scene_t *scene)
{
	switch_scene(win, scene, scene[win->scene].map->event);
}
