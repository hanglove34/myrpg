/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	change_stat_heros(win_t *win)
{
	sfText_setString(win->heros.stat.txt[0].txt,
		my_getstr(win->heros.stat.stat_end[0]));
	sfText_setString(win->heros.stat.txt[1].txt,
		my_getstr(win->heros.stat.stat_end[1]));
	sfText_setString(win->heros.stat.txt[2].txt,
		my_getstr(win->heros.stat.stat_end[2]));
	sfText_setString(win->heros.stat.txt[3].txt,
		my_getstr(win->heros.stat.stat_end[3]));
	sfText_setString(win->heros.stat.txt[4].txt,
		my_getstr(win->heros.stat.stat_end[4]));
	sfText_setString(win->heros.stat.txt[5].txt,
		my_getstr(win->heros.stat.stat_end[5]));
	sfText_setString(win->heros.stat.txt[6].txt,
		my_getstr(win->heros.stat.gold));
}

void	display_stat_of_heros(win_t *win)
{
	sfVector2f pos = {450, 200};
	int c = 0;

	change_stat_heros(win);
	sfRectangleShape_setPosition(win->background[2].rect, pos);
	sfRenderWindow_drawRectangleShape(win->win,
		win->background[2].rect, NULL);
	for (; c != 7; c++) {
		sfRenderWindow_drawText(win->win, win->heros.stat.txt[c].txt,
		NULL);
	}
	display_pict_stat(win);
}
