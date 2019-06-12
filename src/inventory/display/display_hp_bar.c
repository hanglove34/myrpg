/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	display_hp(win_t *win)
{
	float percent = (float)win->heros.stat.stat_end[0] /
	(float)win->heros.stat.all_hp;
	float ref = 370 * percent;
	sfVector2f size = {ref, 20};

	sfRectangleShape_setSize(win->background[5].rect, size);
	sfRenderWindow_drawRectangleShape(win->win,
	win->background[5].rect, NULL);
}

void	display_hp_bar(win_t *win)
{
	sfText_setPosition(win->lvl, (sfVector2f){55, 20});
	sfText_setCharacterSize(win->lvl, 50);
	sfText_setColor(win->lvl, sfWhite);
	char *lvl = my_getstr(win->heros.stat.lvl);
	sfRenderWindow_drawRectangleShape(win->win,
	win->background[4].rect, NULL);
	display_hp(win);
	sfRenderWindow_drawRectangleShape(win->win,
	win->background[7].rect, NULL);
	sfRenderWindow_drawRectangleShape(win->win,
	win->background[8].rect, NULL);
	sfRenderWindow_drawSprite(win->win, win->hp_spr, NULL);
	sfText_setFont(win->lvl, win->font);
	sfText_setString(win->lvl, lvl);
	sfRenderWindow_drawText(win->win, win->lvl, NULL);
	free(lvl);
}
