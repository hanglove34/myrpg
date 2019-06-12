/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** mort au header vide
*/

#include "my.h"

void	button_setttings(win_t *win)
{
	for (int i = 0, nb[4] = {3, 4, 10, 11}; i < 4; i++)
		sfRenderWindow_drawSprite(win->win,
		win->menu.button[nb[i]].spt, NULL);
	for (int i = 0, nb[2] = {8, 9}; i < 2; i++)
		sfRenderWindow_drawText(win->win,
		win->menu.button[nb[i]].text, NULL);

}

void	display_bar_sound(win_t *win)
{
	int nb = win->volmusic / 25;

	if (nb != 0)
		for (int i = 10; nb != 0; nb--, i++)
			sfRenderWindow_drawRectangleShape(win->win,
			win->background[i].rect, NULL);
}

int	bar_luminosity(win_t *win)
{
	int nb = win->luminosity / 30;

	switch (nb) {
		case 0:
		return (5);
		case 1:
		return (4);
		case 2:
		return (3);
		case 3:
		return (2);
		case 4:
		return (1);
		case 5:
		return (0);
	}
}

void	display_bar_luminosity(win_t *win)
{
	int nb = bar_luminosity(win);

	if (nb != 0)
		for (int i = 10; nb != 0; nb--, i++) {
			win->background[i].pos.x -= 10;
			win->background[i].pos.y += 80;
			sfRectangleShape_setPosition(win->background[i].rect,
			win->background[i].pos);
			sfRenderWindow_drawRectangleShape(win->win,
			win->background[i].rect, NULL);
			win->background[i].pos.x += 10;
			win->background[i].pos.y -= 80;
			sfRectangleShape_setPosition(win->background[i].rect,
			win->background[i].pos);
		}
}

void	settings(win_t *win)
{
	sfRenderWindow_drawRectangleShape(win->win,
	win->background[15].rect, NULL);
	if (win->ver[3] == 1) {
		button_setttings(win);
		display_bar_sound(win);
		display_bar_luminosity(win);
	}
}
