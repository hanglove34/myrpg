/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	display_pict_stat(win_t *win)
{
	int c = 0;
	for (; c != 7; c++)
		sfRenderWindow_drawSprite(win->win, win->pict[c].spt, NULL);
}
