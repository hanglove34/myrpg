/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	right_click_sell_item(npc_t *npc, win_t *win)
{
	int i = 0;
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f pos = {win->evt.mouseButton.x, win->evt.mouseButton.y};

	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	while (i != 31) {
		if (pos.x > win->invent[i].pos.x &&
		pos.x < win->invent[i].pos.x + 72 &&
		pos.y > win->invent[i].pos.y && win->invent[i].state[0] != 0
		&& pos.y < win->invent[i].pos.y + 75) {
			win->heros.stat.gold +=
			win->item[win->invent[i].state[0]].stat.gold / 2;
			win->invent[i].state[0] = 0;
			classement_inv(win);
			play_sound(win, 1);
		}
		i++;
	}
}

void	print_item_price_sell(npc_t *npc, obj_t item, win_t *win)
{
	npc->merch.sell_str = my_getstr(item.stat.gold / 2);
	sfText_setPosition(npc->merch.stat[7], (sfVector2f){175, 605});
	sfText_setString(npc->merch.stat[7], npc->merch.sell_str);
	sfRenderWindow_drawText(win->win, npc->merch.stat[7], NULL);
	sfText_setPosition(npc->merch.stat[7], (sfVector2f){385, 605});
	sfSprite_setPosition(npc->merch.pict[7], (sfVector2f){125, 605});
	sfRenderWindow_drawSprite(win->win, npc->merch.pict[7], NULL);
	sfSprite_setPosition(npc->merch.pict[7], (sfVector2f){335, 605});
}

void	merch_give_item(merch_item_t *items, win_t *win)
{
	merch_item_t *tmp = items;

	while (tmp) {
		if (tmp->state[0] == -1) {
			play_sound(win, 1);
			win_give_item(win, tmp->nb);
		}
		tmp = tmp->next;
	}
}

void	restart_merchant(npc_t *npc, win_t *win)
{
	merch_item_t *tmp = npc->merch.items;
	int items = has_more_item(npc, win);

	free(npc->merch.sum_str);
	npc->merch.sum_str = my_strdup("0");
	sfText_setString(npc->merch.stat[7], npc->merch.sum_str);
	while (tmp) {
		tmp->state[0] = 0;
		sfSprite_setColor(tmp->square, sfWhite);
		tmp = tmp->next;
	}
	while (items == 1 || items == 3) {
		go_left_merch(npc, win);
		items = has_more_item(npc, win);
	}
}
