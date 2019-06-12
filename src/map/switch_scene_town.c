/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

void	switch_other_scene_town(win_t *win, scene_t *scene, int nb)
{
	switch (nb) {
		case 40:
			my_switch_scene(4,
			(sfFloatRect){-40, -97,
			31, 362}, scene, win);
			break;
		case 41:
			my_switch_scene(4,
			(sfFloatRect){-490, -40,
			682, 38}, scene, win);
			break;
		case 50:
			my_switch_scene(5,
			(sfFloatRect){-40, -115,
			646, 401}, scene, win);
			break;
	}
}

void	switch_scene_town(win_t *win, scene_t *scene, int nb)
{
	switch (nb) {
		case 20:
			my_switch_scene(2, (sfFloatRect){-40, -120,
			325, 479},
			scene, win);
			play_music(win, 1, 0);
			get_cine_num(win, scene[win->scene], 2);
			break;
		case 30:
			my_switch_scene(3, (sfFloatRect){-40, -40,
			145, 180}, scene, win);
			get_cine_num(win, scene[win->scene], 3);
			break;
		case 31:
			my_switch_scene(3, (sfFloatRect){-556, -40,
			1261, 276}, scene, win);
			break;
		default:
			switch_other_scene_town(win, scene, nb);
	}
}
