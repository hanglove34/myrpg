/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	mouse_detect_take(sfVector2i posi, obj_t *button, mouse_t *mouse,
	int c)
{
	if ((posi.x > button->pos.x && posi.x < (button->pos.x + 72))
	&& (posi.y > button->pos.y && posi.y < (button->pos.y + 75))) {
		mouse->ver = 1;
		mouse->item = button->state[0];
		button->state[0] = 0;
		mouse->save = button->pos;
		mouse->inv = c;
		mouse->type = button->type;
	}
}

void	mouse_presse(win_t *win, sfVector2i pos)
{
	int c = 0;

	while (c != 31) {
		if (win->invent[c].state[0] != 0)
			mouse_detect_take(pos, &win->invent[c], &win->mouse,
			c);
		c++;
	}
}

void	classement_inv(win_t *win)
{
	int nb = 6;
	int ver = 0;

	while (nb != 30) {
		if (win->invent[nb].state[0] == 0 &&
		win->invent[nb + 1].state[0] != 0) {
			win->invent[nb].state[0] =
			win->invent[nb + 1].state[0];
			win->invent[nb + 1].state[0] = 0;
			classement_inv(win);
		}
		nb++;
	}
}

void	drag_and_drop_inv(win_t *win, sfVector2i pos)
{
	if (win->evt.type == sfEvtMouseButtonPressed &&
	win->evt.mouseButton.button == sfMouseLeft)
		mouse_presse(win, pos);
	else if (win->evt.type == sfEvtMouseButtonReleased  &&
	win->evt.mouseButton.button == sfMouseLeft) {
		mouse_pose(win, pos);
		classement_inv(win);
		change_stat_item_heros(win);
	}
}
