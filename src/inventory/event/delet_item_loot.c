/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	delet_item_loot(purse_t *purse)
{
	loot_t *tmp = purse->loot;

	if (tmp && tmp->del == 1) {
		purse->loot = purse->loot->next;
		return;
	}
	for (; tmp && tmp->next && tmp->next->del != 1; tmp = tmp->next);
	if (tmp && tmp->next && tmp->next->del == 1) {
		tmp->next = tmp->next->next;
	}
}

void	delet_purse_loot(win_t *win)
{
	purse_t *tmp = win->purse;

	if (tmp && tmp->loot == NULL) {
		loot_button(tmp, win);
		change_ver_mouse(win);
		display_cursor(win);
		win->purse = win->purse->next;
		return;
	}
	for (; tmp && tmp->next; tmp = tmp->next) {
		if (tmp->next->loot == NULL) {
			loot_button(tmp->next, win);
			change_ver_mouse(win);
			display_cursor(win);
			tmp->next = tmp->next->next;
			break;
		}
	}
}
