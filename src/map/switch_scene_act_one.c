/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

void	switch_scene_tuto(win_t *win, scene_t *scene, int nb)
{
	switch (nb) {
		case 10:
			my_switch_scene(1,
			(sfFloatRect){-40, -40,
			WIDTH / 2 - 70, HEIGHT / 2 - 30},
			scene, win);
			break;
		case 00:
			my_switch_scene(0,
			(sfFloatRect){0, -200,
			WIDTH / 2 - 40, 720},
			scene, win);
			break;
	}
}

void	switch_scene_act_one(win_t *win, scene_t *scene, int nb)
{
	if (nb < 20)
		switch_scene_tuto(win, scene, nb);
	else if (nb < 60)
		switch_scene_town(win, scene, nb);
	else
		switch_scene_castle(win, scene, nb);
}
