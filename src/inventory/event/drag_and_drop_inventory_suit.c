/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	change_item_invent(win_t *win)
{
	int nb = 6;

	for (; win->invent[nb].state[0] != 0; nb++);
	win->invent[nb].state[0] = win->mouse.item;
}

void	pose_item(win_t *win, int c)
{
	if (win->invent[c].type == INV) {
		if (win->invent[c].state[0] != 0  && win->invent[c].type ==
			win->mouse.type) {
			win->invent[win->mouse.inv].state[0] =
			win->invent[c].state[0];
			win->invent[c].state[0] = win->mouse.item;
		} else
			change_item_invent(win);
	} else {
		if (win->invent[c].state[0] != 0) {
			win->invent[win->mouse.inv].state[0] =
			win->invent[c].state[0];
			win->invent[c].state[0] = win->mouse.item;
		} else
			win->invent[c].state[0] = win->mouse.item;
	}
	init_struct_mouse(&win->mouse);
}

void	return_item_base(win_t *win)
{
	win->invent[win->mouse.inv].state[0] = win->mouse.item;
	init_struct_mouse(&win->mouse);
}

void	mouse_pose(win_t *win, sfVector2i posi)
{
	int c = 0;

	while (c != 31) {
		if ((posi.x > win->invent[c].pos.x && posi.x <
		(win->invent[c].pos.x + 72)) && (posi.y > win->invent[c].pos.y
		&& posi.y < (win->invent[c].pos.y + 75))
		&& (win->invent[c].type == INV
		|| win->invent[c].type == win->item[win->mouse.item].type)){
			win->mouse.cp = 1;
			break;
		} else
			win->mouse.cp = 0;
		c++;
	}
	if (win->mouse.cp == 1)
		pose_item(win, c);
	else
		return_item_base(win);
}
