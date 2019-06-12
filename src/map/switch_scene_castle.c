/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

void	switch_other_scene_castle(win_t *win, scene_t *scene, int nb)
{
	switch (nb) {
		case 71:
			my_switch_scene(7,
			(sfFloatRect){-121, -40,
			682, 12},
			scene, win);
			break;
		case 80:
			my_switch_scene(8,
			(sfFloatRect){-52, -319,
			682, 720},
			scene, win);
			get_cine_num(win, scene[win->scene], 4);
			break;
	}
}

void	switch_scene_castle(win_t *win, scene_t *scene, int nb)
{
	switch (nb) {
		case 60:
			my_switch_scene(6,
			(sfFloatRect){-148, -2516, 682, 720}, scene, win);
			break;
		case 61:
			my_switch_scene(6,
			(sfFloatRect){-139, -38, 682, 21}, scene, win);
			break;
		case 70:
			my_switch_scene(7,
			(sfFloatRect){-106, -559, 682, 720}, scene, win);
			break;
		default:
			switch_other_scene_castle(win, scene, nb);
			break;
	}
}
