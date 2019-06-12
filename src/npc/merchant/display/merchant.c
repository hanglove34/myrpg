/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int	has_more_item(npc_t *npc, win_t *win)
{
	merch_item_t *tmp = npc->merch.items;
	int left = 0;
	int right = 0;

	while (tmp) {
		if (tmp->pos.x < 20)
			left += 1;
		else if (tmp->pos.x > 500)
			right += 1;
		tmp = tmp->next;
	}
	if (left == 0 && right == 0)
		return (0);
	else if (left > 0 && right > 0)
		return (3);
	return ((left > 0 && right == 0) ? 1 : 2);
}

void	change_texture_merch(merch_item_t *item, win_t *win, sfSprite *spr,
	npc_t *npc)
{
	switch (item->state[0]) {
		case (-1):
			sfSprite_setTexture(spr, win->invent[0].img, sfTrue);
			sfSprite_setColor(spr, sfGreen);
			break;
		case (1):
			sfSprite_setTexture(spr, win->invent[0].img, sfTrue);
			sfSprite_setColor(spr, sfWhite);
			break;
		case (0):
			sfSprite_setTexture(spr, win->invent[1].img, sfTrue);
			break;
	}
}

void	merchant(npc_t *npc, win_t *win)
{
	if (npc->type != MERCH || npc->tree->main[npc->txt_i]) {
		sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
		npc->state[3] = 0;
		return;
	}
	merch_item_t *tmp = npc->merch.items;
	npc->state[3] = 1;
	sfRenderWindow_setMouseCursorVisible(win->win, sfTrue);
	while (tmp) {
		change_texture_merch(tmp, win, tmp->square, npc);
		tmp = tmp->next;
	}
	display_merch(npc, win);
	merch_inventory_handling(win);
	show_sell_price(npc, win);
	arrow_animations(win, npc);
}
