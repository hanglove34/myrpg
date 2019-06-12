/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "my.h"

void	change_color_set_click(win_t *win, int nb)
{
	if (win->evt.mouseButton.x > win->menu.button[nb].pos.x &&
	win->evt.mouseButton.x < win->menu.button[nb].pos.x + 300) {
		if (win->evt.mouseButton.y > win->menu.button[nb].pos.y &&
		win->evt.mouseButton.y < win->menu.button[nb].pos.y + 51) {
			sfText_setColor(win->menu.button[nb].text, sfYellow);
		}
	}
}
