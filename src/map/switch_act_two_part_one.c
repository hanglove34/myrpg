/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

void	switch_deep_wood_and_boss(win_t *win,
	scene_t *scene, int nb)
{
	switch (nb) {
		case 130:
			my_switch_scene(13,
			(sfFloatRect){-40, -997, 548, 719}, scene, win);
			break;
		case 131:
			my_switch_scene(13,
			(sfFloatRect){-40, -40, 569, 41}, scene, win);
			break;
		case 140:
			my_switch_scene(14,
			(sfFloatRect){-40, -517, 560, 720}, scene, win);
			break;
		case 100:
			my_switch_scene(10,
			(sfFloatRect){0, 0, 743, 553}, scene, win);
			break;
	}
}

void	switch_forest_entrance_and_camp(win_t *win,
	scene_t *scene, int nb)
{
	switch (nb) {
		case 110:
			my_switch_scene(11,
			(sfFloatRect){-355, -517, 1243, 548}, scene, win);
			break;
		case 111:
			my_switch_scene(11,
			(sfFloatRect){-166, -40, 682, 32}, scene, win);
			break;
		case 120:
			my_switch_scene(12,
			(sfFloatRect){-160, -1717, 682, 721}, scene, win);
			break;
		case 121:
			my_switch_scene(12,
			(sfFloatRect){-355, -40, 703, 34}, scene, win);
			break;
		default :
			switch_deep_wood_and_boss(win, scene, nb);
	}
}

void	switch_act_two_part_one(win_t *win, scene_t *scene, int nb)
{
	switch (nb) {
		case 90:
			my_switch_scene(9,
			(sfFloatRect){-757, -517, 1257, 367}, scene, win);
			get_cine_num(win, scene[win->scene], 6);
			break;
		case 91:
			my_switch_scene(9,
			(sfFloatRect){-757, -208, 987, 361}, scene, win);
			break;
		case 92:
			my_switch_scene(9,
			(sfFloatRect){-40, -517, 30, 430}, scene, win);
			break;
		default :
			switch_forest_entrance_and_camp(win, scene, nb);
	}
}
