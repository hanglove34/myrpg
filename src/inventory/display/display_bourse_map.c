/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	display_loot(purse_t *purse, win_t *win)
{
	purse_t *tmp = purse;

	while (tmp != NULL) {
		if (win->scene == tmp->map) {
			sfRenderWindow_drawSprite(win->win, tmp->sprt.spt,
			NULL);
		}
		tmp = tmp->next;
	}
}
