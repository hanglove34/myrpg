/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	display_merch_arrow(npc_t *npc, win_t *win)
{
	merch_item_t *tmp = npc->merch.items;

	while (tmp) {
		if (tmp->pos.x < 20) {
			sfRenderWindow_drawSprite(win->win,
			npc->merch.left_arrow, NULL);

		} else if (tmp->pos.x > 500) {
			sfRenderWindow_drawSprite(win->win,
			npc->merch.right_arrow, NULL);
		}
		tmp = tmp->next;
	}
}

void	click_left_arrow(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};
	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	int items = has_more_item(tmp_npc, win);

	if (evt.x >= 25 && evt.x <= 73 && evt.y >= 460 && evt.y <= 508 &&
	(items == 1 || items == 3)) {
		sfSprite_setColor(tmp_npc->merch.left_arrow, sfWhite);
		go_left_merch(tmp_npc, win);
	}
}

void	click_right_arrow(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};
	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	int items = has_more_item(tmp_npc, win);

	if (evt.x >= 573 && evt.x <= 621 && evt.y >= 460 && evt.y <= 508 &&
	items >= 2) {
		sfSprite_setColor(tmp_npc->merch.right_arrow, sfWhite);
		go_right_merch(tmp_npc, win);
	}
}

void	go_right_merch(npc_t *npc, win_t *win)
{
	merch_item_t *tmp = npc->merch.items;

	while (tmp) {
		tmp->pos.x -= 102;
		sfSprite_setPosition(tmp->item,
		(sfVector2f){tmp->pos.x + 13, tmp->pos.y + 13});
		sfSprite_setPosition(tmp->square, tmp->pos);
		tmp = tmp->next;
	}
}

void	go_left_merch(npc_t *npc, win_t *win)
{
	merch_item_t *tmp = npc->merch.items;

	while (tmp) {
		tmp->pos.x += 102;
		sfSprite_setPosition(tmp->item,
		(sfVector2f){tmp->pos.x + 13, tmp->pos.y + 13});
		sfSprite_setPosition(tmp->square, tmp->pos);
		tmp = tmp->next;
	}
}
