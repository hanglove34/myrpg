/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	draw_type_stat(win_t *win, sfVector2f pos, int *nb, int posi)
{
	sfVector2f p = {pos.x + win->invent[nb[0]].pos.x + posi, pos.y +
	win->invent[nb[0]].pos.y};
	sfText_setPosition(
	win->item[win->invent[0].state[0]].stat.txt[nb[1]].txt, p);
	sfRenderWindow_drawText(win->win,
	win->item[win->invent[0].state[0]].stat.txt[nb[1]].txt, NULL);
}

void	draw_back_of_stat(win_t * win, int c, int pos)
{
	sfVector2f p = {win->invent[c].pos.x + pos, win->invent[c].pos.y};
	sfRectangleShape_setPosition(win->background[1].rect, p);
	sfRenderWindow_drawRectangleShape(win->win,
		win->background[1].rect, NULL);
}

void	draw_stat_item_right(win_t *win, int nb, int c, sfVector2f pos)
{
	sfVector2f p = {pos.x + win->invent[c].pos.x + 145, pos.y +
	win->invent[c].pos.y};
	sfText_setPosition(win->item[win->invent[c].state[0]].stat.txt[nb].txt,
	p);
	sfRenderWindow_drawText(win->win,
	win->item[win->invent[c].state[0]].stat.txt[nb].txt, NULL);
}

void	draw_stat_item_left(win_t *win, int nb, int c, sfVector2f pos)
{
	sfVector2f p = {pos.x + win->invent[c].pos.x - 30, pos.y +
	win->invent[c].pos.y};
	sfText_setPosition(win->item[win->invent[c].state[0]].stat.txt[nb].txt,
	p);
	sfRenderWindow_drawText(win->win,
	win->item[win->invent[c].state[0]].stat.txt[nb].txt, NULL);
}
