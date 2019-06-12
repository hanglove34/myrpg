/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	check_button_pause(menu_t *menu, sfMouseMoveEvent evt, int i)
{
	if (evt.x > menu->button[i].pos.x &&
	evt.x < menu->button[i].pos.x + 300) {
		if (evt.y > menu->button[i].pos.y &&
		evt.y < menu->button[i].pos.y + 51) {
			sfText_setColor(menu->button[i].text, sfWhite);
			menu->button[i].state[0] = 1;
			return;
		}
	}
	menu->button[i].state[0] = 0;
	sfText_setColor(menu->button[i].text, sfBlack);
}

void	check_click_pause(win_t *win, sfMouseButtonEvent evt, int i,
	scene_t *scene)
{
	if (evt.x > win->menu.button[i].pos.x &&
	evt.x < win->menu.button[i].pos.x + 300) {
		if (evt.y > win->menu.button[i].pos.y &&
		evt.y < win->menu.button[i].pos.y + 51)
			win->menu.button[i].ptr_cmd(win, scene);
	}
}

void	event_pause(win_t *win, scene_t *scene)
{
	test_settings_event(win, scene);
	if (win->evt.type == sfEvtKeyReleased) {
		if (win->evt.key.code == sfKeyEscape && win->state == 0) {
			win->state = 1;
			play_sound(win, 3);
			sfRenderWindow_setMouseCursorVisible(win->win, sfTrue);
		} else if (win->evt.key.code == sfKeyEscape
		&& win->state == 1) {
			win->state = 0;
			play_sound(win, 3);
			sfRenderWindow_setMouseCursorVisible(win->win,
				sfFalse);
		}
	}
	while (win->evt.type == sfEvtMouseButtonReleased && win->state == 1) {
		check_click_pause(win, win->evt.mouseButton, 1, scene);
		break;
	}
	if (win->evt.type == sfEvtMouseMoved && win->state == 1)
		check_button_pause(&win->menu, win->evt.mouseMove, 1);
}

void	draw_menu_pause(win_t *win)
{
	int nb[3] = {1, 2, 6};

	sfRenderWindow_drawSprite(win->win, win->quest_book.spr, NULL);
	for (int i = 0; i < 3; i++) {
		if (win->menu.button[nb[i]].state[0] == 1) {
			blink_cursor_menu(&win->menu.button[nb[i]]);
			sfRenderWindow_drawSprite(win->win,
			win->menu.button[nb[i]].spt, NULL);
			sfSprite_setTextureRect(win->menu.button[nb[i]].spt,
			win->menu.button[nb[i]].rect);
		}
		sfRenderWindow_drawText(win->win,
		win->menu.button[nb[i]].text, NULL);
	}

}
