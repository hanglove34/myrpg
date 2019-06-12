/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	add_stat_heros(win_t *win, int *nb)
{
	float c = (float)win->heros.stat.stat_end[0] /
	(float)win->heros.stat.all_hp;
	win->heros.stat.stat_end[0] = (nb[0] * c);
	win->heros.stat.stat_end[1] = nb[1];
	win->heros.stat.stat_end[2] = nb[2];
	win->heros.stat.stat_end[3] = nb[3];
	win->heros.stat.stat_end[4] = nb[4];
	win->heros.stat.stat_end[5] = nb[5];
	win->heros.stat.all_hp = nb[0];
}

void	add_base_stat_item(win_t *win, int *nb)
{
	nb[0] = win->heros.stat.hp;
	nb[1] = win->heros.stat.armor;
	nb[2] = win->heros.stat.atk;
	nb[3] = win->heros.stat.crit;
	nb[4] = win->heros.stat.spd;
	nb[5] = win->heros.stat.mana;
}

void	change_stat_item_heros(win_t *win)
{
	int nb[6];
	int c = 1;

	add_base_stat_item(win, nb);
	while (c != 6) {
		if (win->invent[c].state[c] != 0)
			nb[0] += win->item[win->invent[c].state[0]].stat.hp;
			nb[1] += win->item[win->invent[c].state[0]].stat.armor;
			nb[2] += win->item[win->invent[c].state[0]].stat.atk;
			nb[3] += win->item[win->invent[c].state[0]].stat.crit;
			nb[4] += win->item[win->invent[c].state[0]].stat.spd;
			nb[5] += win->item[win->invent[c].state[0]].stat.mana;
		c++;
	}
	add_stat_heros(win, nb);
}
