/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	display_mouse_dad(win_t *win)
{
	int c = win->mouse.item;
	sfVector2f pos;
	pos.x = win->mouse.pos.x - 20;
	pos.y = win->mouse.pos.y - 20;

	if (win->mouse.ver == 1) {
		sfSprite_setPosition(win->item[c].spt, pos);
		sfRenderWindow_drawSprite(win->win, win->item[c].spt, NULL);
	}
}
