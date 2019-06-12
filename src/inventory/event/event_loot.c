/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	loot_button(purse_t *tmp, win_t *win)
{
	if (tmp->ver == 0) {
		tmp->ver = 1;
		win->state = -5;
	}
	else if (tmp->ver == 1) {
		tmp->ver = 0;
		win->state = 0;
	}
}

int	test_touch_loot(win_t *win, purse_t *tmp)
{
	if (win->heros.pos.x >= tmp->pos.x - 20 &&
	win->heros.pos.x <= tmp->pos.x + 35 &&
	win->heros.pos.y >= tmp->pos.y - 10 &&
	win->heros.pos.y <= tmp->pos.y + 80 && win->scene == tmp->map) {
		loot_button(tmp, win);
		change_ver_mouse(win);
		display_cursor(win);
		return (1);
	}
	return (0);
}

void	event_loot(win_t *win)
{
	purse_t *tmp = win->purse;

	if (win->evt.type != sfEvtKeyReleased)
		return;
	if (win->evt.key.code != sfKeyReturn)
		return;
	while (tmp != NULL) {
		if (test_touch_loot(win, tmp) == 1) {
			reset_value(win);
			play_sound(win, 4);
			break;
		}
		tmp = tmp->next;
	}
}
