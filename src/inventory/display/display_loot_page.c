/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	display_loot_itm(loot_t *loot, win_t *win, sfVector2f pos)
{
	sfSprite_setPosition(win->item[loot->item].spt, pos);
	sfRenderWindow_drawSprite(win->win, win->item[loot->item].spt, NULL);
	pos.x = 340;
	loot->add.pos.x = pos.x;
	loot->add.pos.y = pos.y;
	sfSprite_setPosition(loot->add.spt, pos);
	sfRenderWindow_drawSprite(win->win, loot->add.spt, NULL);
}

void	loot_inv(win_t *win, purse_t *tmp)
{
	sfVector2f pos = {270, 230};
	loot_t *loot = tmp->loot;

	display_inventory_merch(win);
	display_item(win);
	merch_inventory_handling(win);
	for (; loot; loot = loot->next, pos.y += 75)
		display_loot_itm(loot, win, pos);
}

void	loot_event(purse_t *tmp, win_t *win)
{
	if (tmp && tmp->ver == 1) {
		sfRenderWindow_drawRectangleShape(win->win,
		win->background[6].rect, NULL);
		loot_inv(win, tmp);
	}
}

void	display_loot_page(win_t *win)
{
	purse_t *tmp = win->purse;

	for (; tmp; tmp = tmp->next)
		if (tmp->ver == 1)
			break;
	loot_event(tmp, win);
	restore_invent_merch(win);
}
