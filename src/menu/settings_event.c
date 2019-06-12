/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"

void	check_click_pause_volume(win_t *win, sfMouseButtonEvent evt, int i,
	scene_t *scene)
{
	if (evt.x > win->menu.button[i].pos.x &&
	evt.x < win->menu.button[i].pos.x + 41) {
		if (evt.y > win->menu.button[i].pos.y &&
		evt.y < win->menu.button[i].pos.y + 41)
			win->menu.button[i].ptr_cmd(win, scene);
	}
}

void	click_button_change_color(win_t *win)
{
	int nb[5] = {0, 1, 2, 5, 6};

	if (win->evt.type == sfEvtMouseButtonPressed)
		for (int i = 0; i < 5; i++) {
			change_color_set_click(win, nb[i]);
		}
}

void close_settings(win_t *win)
{
	if (win->evt.type == sfEvtKeyReleased)
		if (win->evt.key.code == sfKeyEscape)
			win->ver[3] = 0;
}

void	test_settings_event(win_t *win, scene_t *scene)
{
	int nb[4] = {3, 4, 10, 11};
	int c[2] = {2, 6};
	if (win->state == 0)
		return;
	close_settings(win);
	click_button_change_color(win);
	for (int i = 0; i < 2 && win->state != 5 && win->state != -5; i++) {
		if (win->evt.type == sfEvtMouseButtonReleased)
			check_click_pause(win, win->evt.mouseButton, c[i],
				scene);
		if (win->evt.type == sfEvtMouseMoved)
			check_button_pause(&win->menu,
			win->evt.mouseMove, c[i]);
	} if (win->evt.type == sfEvtMouseButtonReleased &&
	win->evt.mouseButton.button == sfMouseLeft && win->ver[3] == 1) {
		for (int i = 0; i < 4; i++) {
			check_click_pause_volume(win, win->evt.mouseButton,
			nb[i], scene);
		}
	}
}

void	settings_init(win_t *win)
{
	win->state = 2;
	win->volmusic = 50;
	win->luminosity = 0;
	win->lvl = sfText_create();
}
