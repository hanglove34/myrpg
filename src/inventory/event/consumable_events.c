/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	drink_potion(win_t *win, int i)
{
	int value;

	if (win->item[win->invent[i].state[0]].type == LIFE &&
	win->heros.stat.stat_end[0] < win->heros.stat.all_hp) {
		value = win->item[win->invent[i].state[0]].stat.hp;
		win->heros.stat.stat_end[0] += value;
		if (win->heros.stat.stat_end[0] > win->heros.stat.all_hp)
			win->heros.stat.stat_end[0] = win->heros.stat.all_hp;
		win->invent[i].state[0] = 0;
	}
}

void	click_potion(win_t *win)
{
	sfVector2f pos = {win->evt.mouseButton.x, win->evt.mouseButton.y};
	int i = 0;

	while (i != 31) {
		if (pos.x > win->invent[i].pos.x &&
		pos.x < win->invent[i].pos.x + 72 &&
		pos.y > win->invent[i].pos.y &&
		pos.y < win->invent[i].pos.y + 75 &&
		win->invent[i].state[0] != 0 &&
		win->item[win->invent[i].state[0]].state[0] == 2) {
			drink_potion(win, i);
			classement_inv(win);
			break;
		}
		i += 1;
	}
}

void	consumable_released(win_t *win)
{
	if (win->evt.mouseButton.button == sfMouseRight) {
		click_potion(win);
	}
}

void	consumable_events(win_t *win)
{
	switch (win->evt.type) {
		case (sfEvtMouseButtonReleased):
			consumable_released(win);
			break;
	}
}
