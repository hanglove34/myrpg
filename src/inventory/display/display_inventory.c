/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	display_mouse_case(win_t *win, int c)
{
	if (win->invent[c].ver == 0) {
		sfRenderWindow_drawSprite(win->win,
			win->invent[c].spt, NULL);
	}
	else if (win->invent[c].ver == 1) {
		sfSprite_setPosition(win->invent[0].spt, win->invent[c].pos);
		sfRenderWindow_drawSprite(win->win, win->invent[0].spt, NULL);
		if (win->invent[c].type == HELMET || win->invent[c].type ==
		ARMOR || win->invent[c].type == WEAPON || win->invent[c].type
		== SHOE || win->invent[c].type == SHIELD)
			sfRenderWindow_drawText(win->win,
			win->invent[c].txt.txt, NULL);
	}
}

void	dsp_it(win_t *win, sfVector2f pos, obj_t *item, int c)
{
	pos.x = pos.x + 13;
	pos.y = pos.y + 15;
	sfSprite_setPosition(item[c].spt, pos);
	sfRenderWindow_drawSprite(win->win, item[c].spt, NULL);
}

void	display_item(win_t *win)
{
	int c = 1;
	int nb = 0;

	while (c != 31) {
		for (nb = 0; nb != win->invent[c].state[0]; nb++);
		dsp_it(win, win->invent[c].pos, win->item, nb);
		c++;
	}
}

void	display_inventory(win_t *win)
{
	int c = 1;

	if (win->ver[1] == 1) {
		sfRenderWindow_drawRectangleShape(win->win,
			win->background[0].rect, NULL);
		display_stat_of_heros(win);
		while (c != 31) {
			display_mouse_case(win, c);
			c++;
		}
		sfRenderWindow_drawSprite(win->win, win->character.spt, NULL);
		display_item(win);
		display_mouse_dad(win);
		display_stat(win);
	}
	display_loot_page(win);
}
