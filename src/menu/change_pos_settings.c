/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg
*/

#include "my.h"

void	replace_settings_menu(win_t *win)
{
	for (int i = 0, nb[4] = {3, 4, 10, 11}; i < 4; i++) {
		win->menu.button[nb[i]].pos.x += 45;
		win->menu.button[nb[i]].pos.y -= 25;
		sfSprite_setPosition(win->menu.button[nb[i]].spt,
		win->menu.button[nb[i]].pos);
	}
	for (int c = 0, i = 10; c < 5; c++, i++) {
		win->background[i].pos.x += 45;
		win->background[i].pos.y -= 25;
		sfRectangleShape_setPosition(win->background[i].rect,
		win->background[i].pos);
	}
	sfText_setPosition(win->menu.button[8].text,
	(sfVector2f){850, 130});
	sfText_setPosition(win->menu.button[9].text,
	(sfVector2f){810, 210});
}

void	change_pos_button(win_t *win)
{
	for (int i = 0, nb[4] = {3, 4, 10, 11}; i < 4; i++) {
		win->menu.button[nb[i]].pos.x -= 45;
		win->menu.button[nb[i]].pos.y += 25;
		sfSprite_setPosition(win->menu.button[nb[i]].spt,
		win->menu.button[nb[i]].pos);
	}
	for (int c = 0, i = 10; c < 5; c++, i++) {
		win->background[i].pos.x -= 45;
		win->background[i].pos.y += 25;
		sfRectangleShape_setPosition(win->background[i].rect,
		win->background[i].pos);
	}
	sfText_setPosition(win->menu.button[8].text,
	(sfVector2f){805, 155});
	sfText_setPosition(win->menu.button[9].text,
	(sfVector2f){775, 235});
}
