/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	change_display_stat_item(win_t *win, int c)
{
	int nb[2];
	nb[0] = c;
	nb[1] = 0;
	sfVector2f pos = {0, 0};

	if (nb[0] < 6) {
		draw_back_of_stat(win, nb[0], 75);
		for (;nb[1] != 6; nb[1]++) {
			draw_type_stat(win, pos, nb, 75);
			draw_stat_item_right(win, nb[1], nb[0], pos);
			pos.y = pos.y + 20;
		}
	} else if (nb[0] >= 6) {
		draw_back_of_stat(win, nb[0], -100);
		for (;nb[1] != 6; nb[1]++) {
			draw_type_stat(win, pos, nb, -100);
			draw_stat_item_left(win, nb[1], nb[0], pos);
			pos.y = pos.y + 20;
		}
	}
}

void	display_stat_item(win_t *win, int c)
{
	if (win->invent[c].state[0] != 0) {
		change_display_stat_item(win, c);
	}
}

void	display_stat(win_t *win)
{
	int c = 1;

	while (c != 31) {
		if (win->invent[c].ver == 1)
			display_stat_item(win, c);
		c++;
	}
}
