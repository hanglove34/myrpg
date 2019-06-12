/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	merch_mouse_pressed(win_t *win, npc_t *npc)
{
	if (win->evt.mouseButton.button == sfMouseLeft) {
		click_sell_item(npc, win);
		arrow_click_merch(win, npc);
	}
}
