/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	display_merch_pict(npc_t *npc, win_t *win)
{
	int i = 0;
	merch_item_t *tmp = npc->merch.items;

	while (i != 8) {
		sfRenderWindow_drawSprite(win->win, npc->merch.pict[i], NULL);
		i += 1;
	}
	sfText_setPosition(npc->merch.stat[7], (sfVector2f){385, 605});
	sfText_setString(npc->merch.stat[7], npc->merch.sum_str);
	sfRenderWindow_drawText(win->win, npc->merch.stat[7], NULL);
	sfText_setString(npc->merch.stat[7], "Sell");
	sfText_setPosition(npc->merch.stat[7], (sfVector2f){47, 584});
	sfText_setCharacterSize(npc->merch.stat[7], 25);
	sfRenderWindow_drawText(win->win, npc->merch.stat[7], NULL);
	sfText_setCharacterSize(npc->merch.stat[7], 32);
}

void	display_inventory_merch(win_t *win)
{
	int i = 1;
	int y = 172.5;
	int x = 900;

	while (i != 6) {
		win->invent[i].pos = (sfVector2f){900 + 73 * (i - 1), 60};
		sfSprite_setPosition(win->invent[i].spt, win->invent[i].pos);
		sfRenderWindow_drawSprite(win->win, win->invent[i].spt, NULL);
		i += 1;
	}
	reset_pos_text_invent_merch(win);
	while (i != 31) {
		sfRenderWindow_drawSprite(win->win, win->invent[i].spt, NULL);
		i += 1;
	}
	for (i = 1; i != 6; i++)
		sfRenderWindow_drawText(win->win, win->invent[i].txt.txt,
		NULL);
}

void	display_merch_stats(npc_t *npc, win_t *win, merch_item_t *tmp)
{
	int i = 0;

	while (i != 7) {
		sfText_setString(npc->merch.stat[i], tmp->stat_str[i]);
		sfRenderWindow_drawText(win->win, npc->merch.stat[i], NULL);
		i += 1;
	}
}

void	display_merch_items(npc_t *npc, win_t *win)
{
	merch_item_t *tmp = npc->merch.items;

	sfRenderWindow_drawSprite(win->win, win->pict[6].spt, NULL);
	sfText_setString(win->heros.stat.txt[6].txt,
	my_getstr(win->heros.stat.gold));
	sfRenderWindow_drawText(win->win, win->heros.stat.txt[6].txt, NULL);
	while (tmp) {
		if (tmp->pos.x > 20 && tmp->pos.x < 500) {
			sfRenderWindow_drawSprite(win->win, tmp->square, NULL);
			sfRenderWindow_drawSprite(win->win, tmp->item, NULL);
		}
		tmp = tmp->next;
	}
}

void	display_merch(npc_t *npc, win_t *win)
{
	sfRenderWindow_drawRectangleShape(win->win,
	win->background[0].rect, NULL);
	sfRenderWindow_drawRectangleShape(win->win, npc->merch.rect, NULL);
	sfRenderWindow_drawSprite(win->win, npc->merch.buy, NULL);
	sfRenderWindow_drawSprite(win->win, npc->merch.sell, NULL);
	merch_item_t *tmp = npc->merch.items;

	while (tmp) {
		if (tmp->state[1] == 1)
			display_merch_stats(npc, win, tmp);
		tmp = tmp->next;
	}
	display_merch_pict(npc, win);
	display_merch_items(npc, win);
	display_inventory_merch(win);
	display_item(win);
	merch_sell_item(npc, win);
	display_merch_arrow(npc, win);
}
