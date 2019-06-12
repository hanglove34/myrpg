/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	win_give_item(win_t *win, int nb)
{
	int c = 6;

	for (;c != 31 && win->invent[c].state[0] != 0; c++);
		win->invent[c].state[0] = nb;
}
