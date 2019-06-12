/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	change_aspect_button(sfVector2i posi, obj_t *button)
{
	button->ver = 0;
	if ((posi.x > button->pos.x && posi.x < (button->pos.x + 72))
	&& (posi.y > button->pos.y && posi.y < (button->pos.y + 75))) {
		button->ver = 1;
	}
}

void	button_detect(win_t *win)
{
	int c = 0;
	sfVector2i posi;

	posi = sfMouse_getPositionRenderWindow(win->win);
	while (c != 31) {
		change_aspect_button(posi, &win->invent[c]);
		c++;
	}
	win->mouse.pos.x = posi.x;
	win->mouse.pos.y = posi.y;
}

void	change_ver_mouse(win_t *win)
{
	if (win->ver[0] == 0)
		win->ver[0] = 1;
	else if (win->ver[0] == 1)
		win->ver[0] = 0;
}

void	change_inventory(win_t *win)
{
	if (win->ver[1] == 0) {
		win->ver[1] = 1;
		win->state = -5;
	}
	else if (win->ver[1] == 1) {
		win->ver[1] = 0;
		win->state = 0;
	}
}

void	analyse_events(win_t *win)
{
	sfVector2i posi = sfMouse_getPositionRenderWindow(win->win);

	if (win->evt.type == sfEvtKeyReleased) {
		if (win->evt.key.code == sfKeyI) {
			play_sound(win, 4);
			reset_value(win);
			change_inventory(win);
			change_ver_mouse(win);
			display_cursor(win);
		}
	}
	if (win->ver[1] == 1) {
		button_detect(win);
		drag_and_drop_inv(win, posi);
	}
	consumable_events(win);
	event_loot(win);
	take_item_loot(win);
}
