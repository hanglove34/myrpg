/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

void	refresh_rectangle(sfRectangleShape *shp, sfVector2f pos,
	sfVector2f sz, sfColor c)
{
	sfRectangleShape_setSize(shp, sz);
	sfRectangleShape_setPosition(shp, pos);
	sfRectangleShape_setFillColor(shp, c);
}

void	set_background_rect(win_t *win)
{
	sfVector2f pos = {400, 410};
	sfVector2f size_max = {500, 25};
	sfRectangleShape *shp2 = sfRectangleShape_create();

	refresh_rectangle(shp2, pos, size_max, sfBlack);
	sfRectangleShape_setOutlineThickness(shp2, 2);
	sfRectangleShape_setOutlineColor(shp2, sfWhite);
	sfRenderWindow_drawRectangleShape(win->win, shp2, NULL);
	sfRectangleShape_destroy(shp2);
}

void	display_loading_rect(int nb, win_t *win)
{
	sfVector2f pos = {400, 410};
	sfVector2f size = {50, 25};
	float offset = 50;
	int i = 0;
	sfRectangleShape *shp = sfRectangleShape_create();

	set_background_rect(win);
	while (i < nb) {
		refresh_rectangle(shp, pos, size, sfGreen);
		sfRenderWindow_drawRectangleShape(win->win, shp, NULL);
		pos.x += offset;
		i++;
	}
	sfRectangleShape_destroy(shp);
}

void	display_loading_text(win_t *win)
{
	sfVector2f pos = {580, 310};
	sfText *text = create_text("Loading",
	pos, win);

	sfText_setCharacterSize(text, 50);
	sfText_setColor(text, sfWhite);
	sfRenderWindow_drawText(win->win, text, NULL);
	sfText_destroy(text);
}

void	print_loading_screen(win_t *win, int nb)
{
	clck_t clck;

	clck.clock = sfClock_create();
	sfRenderWindow_clear(win->win, sfBlack);
	display_loading_text(win);
	display_loading_rect(nb, win);
	clck.time = sfClock_getElapsedTime(clck.clock);
	clck.sec = clck.time.microseconds / 1000000.0;
	sfRenderWindow_display(win->win);
	while (clck.sec < 0.02) {
		if (sfRenderWindow_pollEvent(win->win, &win->evt) &&
		win->evt.type == sfEvtClosed)
				sfRenderWindow_close(win->win);
		clck.time = sfClock_getElapsedTime(clck.clock);
		clck.sec = clck.time.microseconds / 1000000.0;
	}
	sfClock_destroy(clck.clock);
}
