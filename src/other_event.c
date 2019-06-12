/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	different_state(win_t *win, scene_t *scene)
{
	if (win->state == 0)
		heros_event_handle(win);
	if (win->state != -2) {
		analyse_events(win);
		event_pause(win, scene);
	}
}

void	check_pause_draw(win_t *win)
{
	if (win->state == 1)
		draw_menu_pause(win);
}
