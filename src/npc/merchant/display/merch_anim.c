/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	arrow_click_merch(win_t *win, npc_t *npc)
{
	npc_t *tmp_npc = find_active_npc(npc);
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};
	if (!tmp_npc || tmp_npc->state[3] != 1)
		return;
	int items = has_more_item(tmp_npc, win);

	if (evt.x >= 25 && evt.x <= 73 && evt.y >= 460 && evt.y <= 508 &&
	(items == 1 || items == 3))
		sfSprite_setColor(tmp_npc->merch.left_arrow, sfRed);
	else if (evt.x >= 573 && evt.x <= 621 && evt.y >= 460 &&
	evt.y <= 508 && items >= 2)
		sfSprite_setColor(tmp_npc->merch.right_arrow, sfRed);
}

void	arrow_animations(win_t *win, npc_t *npc)
{
	sfVector2i pos = sfMouse_getPositionRenderWindow(win->win);
	int items = has_more_item(npc, win);

	if (pos.x >= 25 && pos.x <= 73 && pos.y >= 460 && pos.y <= 508 &&
	(items == 1 || items == 3))
		sfSprite_setScale(npc->merch.left_arrow, (sfVector2f){2, 2});
	else if (pos.x >= 573 && pos.x <= 621 && pos.y >= 460 &&
	pos.y <= 508 && items >= 2)
		sfSprite_setScale(npc->merch.right_arrow, (sfVector2f){2, 2});
	else {
		sfSprite_setScale(npc->merch.left_arrow,
		(sfVector2f){1.5, 1.5});
		sfSprite_setScale(npc->merch.right_arrow,
		(sfVector2f){1.5, 1.5});
		sfSprite_setColor(npc->merch.left_arrow, sfWhite);
		sfSprite_setColor(npc->merch.right_arrow, sfWhite);
	}
}
