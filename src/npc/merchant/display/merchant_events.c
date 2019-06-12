/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	buy_item(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};
	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	merch_item_t *tmp = tmp_npc->merch.items;
	int sum = 0;
	int gold = win->heros.stat.gold;

	if (evt.x >= 460 && evt.x <= 610 &&
	evt.y >= 600 && evt.y <= 650) {
		while (tmp) {
			sum = (tmp->state[0] == -1)
			? sum + my_getnbr(tmp->stat_str[6]) : sum;
			tmp = tmp->next;
		}
		win->heros.stat.gold = (gold >= sum) ? gold - sum : gold;
		if (gold >= sum)
			merch_give_item(tmp_npc->merch.items, win);
	}
}

void	close_merch(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};

	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	merch_item_t *tmp = tmp_npc->merch.items;

	if (evt.x >= 22 && evt.x <= 54 &&
	evt.y >= 62 && evt.y <= 94) {
		sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
		npc->state[3] = 0;
		npc_active(npc, tmp_npc->i, win);
		restore_invent_merch(win);
		restart_merchant(tmp_npc, win);
		win->state = 0;
		return;
	}
}

void	select_item_merch(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};
	int sum = 0;
	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	merch_item_t *tmp = tmp_npc->merch.items;

	while (tmp) {
		if (evt.x > tmp->pos.x && evt.x < tmp->pos.x + 72 &&
		evt.y > tmp->pos.y && evt.y < tmp->pos.y + 75 &&
		evt.x > 20 && evt.x < 575)
			tmp->state[0] *= -1;
		if (tmp->state[0] == -1)
			sum += win->item[tmp->nb].stat.gold;
		tmp = tmp->next;
	}
	free(tmp_npc->merch.sum_str);
	tmp_npc->merch.sum_str = my_getstr(sum);
}

void	buy_merch_selection(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseMove.x, win->evt.mouseMove.y};

	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	if (evt.x >= 460 && evt.x <= 610 &&
	evt.y >= 600 && evt.y <= 650)
		sfSprite_setColor(tmp_npc->merch.buy, sfGreen);
	else
		sfSprite_setColor(tmp_npc->merch.buy, sfWhite);
}

void	move_selection_merch(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseMove.x, win->evt.mouseMove.y};

	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	merch_item_t *tmp = tmp_npc->merch.items;

	while (tmp) {
		if (evt.x > tmp->pos.x && evt.x < tmp->pos.x + 72 &&
		evt.y > tmp->pos.y && evt.y < tmp->pos.y + 75 &&
		evt.x > 20 && evt.x < 575) {
			tmp->state[0] = (tmp->state[0] == -1) ? -1 : 1;
			tmp->state[1] = 1;
		}
		else {
			tmp->state[0] = (tmp->state[0] == -1) ? -1 : 0;
			tmp->state[1] = 0;
		}
		tmp = tmp->next;
	}
}
