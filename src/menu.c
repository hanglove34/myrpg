/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "my.h"

void	check_click(win_t *win, sfMouseButtonEvent evt, scene_t **scene)
{
	int nb[4] = {0, 1, 5, 7};

	for (int i = 0; i < 4; i++) {
		if (evt.x > win->menu.button[nb[i]].pos.x &&
		evt.x < win->menu.button[nb[i]].pos.x + 300 &&
		evt.y > win->menu.button[nb[i]].pos.y &&
		evt.y < win->menu.button[nb[i]].pos.y + 51) {
			if (nb[i] == 0)
				win->menu.button[nb[i]].reset(win,
				scene);
			else
				win->menu.button[nb[i]].ptr_cmd(win,
				*scene);
		}
	}
}

void	check_button(menu_t *menu, sfMouseMoveEvent evt, win_t *win)
{
	int nb[5] = {0, 1, 2, 5, 7};

	for (int i = 0; i < 5; i++) {
		if (evt.x > menu->button[nb[i]].pos.x &&
		evt.x < menu->button[nb[i]].pos.x + 300 &&
		evt.y > menu->button[nb[i]].pos.y &&
		evt.y < menu->button[nb[i]].pos.y + 51) {
			sfText_setColor(menu->button[nb[i]].text,
			sfWhite);
			menu->button[nb[i]].state[0] = 1;
			return;
		}
		menu->button[nb[i]].state[0] = 0;
		sfText_setColor(menu->button[nb[i]].text, sfBlack);
	}
}

void	event_menu_analyse(win_t *win, scene_t **scene)
{
	int nb[5] = {0, 1, 2, 5, 7};
	if (win->evt.type == sfEvtClosed)
		sfRenderWindow_close(win->win);
	if (win->evt.type == sfEvtMouseMoved)
		check_button(&win->menu, win->evt.mouseMove, win);
	while (win->evt.type == sfEvtKeyPressed && win->state == 2) {
		win->state = 3;
		sfRectangleShape_setFillColor(win->background[0].rect,
		sfColor_fromRGBA(0, 0, 0, 5));
		break;
	}
	if (win->evt.type == sfEvtMouseButtonReleased)
		check_click(win, win->evt.mouseButton, scene);
	if (win->evt.type == sfEvtMouseButtonPressed)
		for (int i = 0; i < 5; i++)
			change_color_set_click(win, nb[i]);
}

void	display_button(win_t *win)
{
	int i[5] = {0, 1, 2, 5, 7};
	int nb = 0;

	if (win->state == 4 || win->state == 5) {
		for (;nb < 5; nb++) {
			sfRenderWindow_drawText(win->win,
			win->menu.button[i[nb]].text, NULL);
			if (win->menu.button[i[nb]].state[0] == 1) {
				blink_cursor_menu(&win->menu.button[i[nb]]);
				sfRenderWindow_drawSprite(win->win,
				win->menu.button[i[nb]].spt, NULL);
				sfSprite_setTextureRect(
				win->menu.button[i[nb]].spt,
				win->menu.button[i[nb]].rect);
			}
		}
	}
	settings(win);
}

void	menu(win_t *win, scene_t **scene)
{
	sfRenderWindow_clear(win->win, sfBlack);
	while (sfRenderWindow_pollEvent(win->win, &win->evt)) {
		event_menu_analyse(win, scene);
		test_settings_event(win, *scene);
	}
	sfRenderWindow_drawSprite(win->win, win->menu.spt, NULL);
	sfSprite_setTextureRect(win->menu.spt, win->menu.rect);
	if (win->state == 2) {
		set_alpha_text(win);
		sfRenderWindow_drawText(win->win, win->menu.text, NULL);
	}
	if (win->state == 3) {
		sfRenderWindow_drawRectangleShape(win->win,
		win->background[0].rect, NULL);
		move_menu(&win->menu, win);
	} while (win->state == 5) {
		draw_credits(win);
		break;
	}
	display_button(win);
	sfRenderWindow_display(win->win);
}
