/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	drag_item_sell(npc_t *tmp_npc, win_t *win, int i)
{
	tmp_npc->merch.state = win->invent[i].state[0];
	sfSprite_setTexture(tmp_npc->merch.mouse,
	win->item[tmp_npc->merch.state].img, sfTrue);
	sfSprite_setTextureRect(tmp_npc->merch.mouse,
	win->item[tmp_npc->merch.state].rect);
	sfSprite_setScale(tmp_npc->merch.sell, (sfVector2f){2, 2});
	win->invent[i].state[0] = 0;
}

void	click_sell_item(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};
	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	int i = 6;
	sfVector2f square;

	while (i != 31) {
		square = win->invent[i].pos;
		if (evt.x >= square.x && evt.x <= square.x + 72 &&
		evt.y >= square.y && evt.y <= square.y + 72 &&
		win->invent[i].state[0] != 0)
			drag_item_sell(tmp_npc, win, i);
		i += 1;
	}
}

void	release_sell_item(npc_t *npc, win_t *win)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};
	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	int i = 6;
	sfVector2f square;

	sfSprite_setScale(tmp_npc->merch.sell, (sfVector2f){1.5, 1.5});
	if (evt.x >= 50 && evt.x <= 100 && evt.y >= 600 && evt.y <= 650 &&
	tmp_npc->merch.state != 0) {
		win->heros.stat.gold += win->item[tmp_npc->merch.state].
		stat.gold / 2;
		play_sound(win, 1);
		classement_inv(win);
	}
	else
		win_give_item(win, tmp_npc->merch.state);
	tmp_npc->merch.state = 0;
}

void	merch_sell_item(npc_t *npc, win_t *win)
{
	if (npc->merch.state == 0)
		return;
	sfVector2i posi = sfMouse_getPositionRenderWindow(win->win);
	sfVector2f pos = {(float)posi.x - 24, (float)posi.y - 24};
	free(npc->merch.sell_str);
	npc->merch.sell_str = my_getstr(win->item[npc->merch.state].
	stat.gold / 2);
	sfSprite_setPosition(npc->merch.pict[7], (sfVector2f){125, 605});
	sfRenderWindow_drawSprite(win->win, npc->merch.pict[7], NULL);
	sfText_setPosition(npc->merch.stat[7], (sfVector2f){175, 605});
	sfText_setString(npc->merch.stat[7], npc->merch.sell_str);
	sfRenderWindow_drawText(win->win, npc->merch.stat[7], NULL);
	sfSprite_setPosition(npc->merch.pict[7], (sfVector2f){335, 605});
	sfText_setPosition(npc->merch.stat[7], (sfVector2f){385, 605});
	sfSprite_setPosition(npc->merch.mouse, (sfVector2f)pos);
	sfRenderWindow_drawSprite(win->win, npc->merch.mouse, NULL);
}

void	show_sell_price(npc_t *npc, win_t *win)
{
	int i = 1;
	if (npc->merch.state != 0)
		return;
	sfVector2i pos = sfMouse_getPositionRenderWindow(win->win);

	while (i != 31) {
		if (pos.x > win->invent[i].pos.x &&
		pos.x < win->invent[i].pos.x + 72 &&
		pos.y > win->invent[i].pos.y && win->invent[i].state[0] != 0
		&& pos.y < win->invent[i].pos.y + 75) {
			print_item_price_sell(npc,
			win->item[win->invent[i].state[0]], win);
		}
		i++;
	}
}
