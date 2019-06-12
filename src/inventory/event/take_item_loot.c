/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	boutton_is_press_loot(loot_t *loot, win_t *win)
{
	win_give_item(win, loot->item);
	loot->del = 1;
}

void	test_mouse_pos_itm(loot_t *loot, win_t *win)
{
	sfVector2f posi = {win->evt.mouseButton.x, win->evt.mouseButton.y};

	if ((posi.x > loot->add.pos.x && posi.x < (loot->add.pos.x + 48))
	&& (posi.y > loot->add.pos.y && posi.y < (loot->add.pos.y + 48)))
			boutton_is_press_loot(loot, win);
}

void	detect_click_pickup(purse_t *loot, win_t *win)
{
	loot_t *tmp = loot->loot;
	for (; tmp; tmp = tmp->next) {
		test_mouse_pos_itm(tmp, win);
	}
	delet_item_loot(loot);
}

void	take_item_loot(win_t *win)
{
	int i = 0;
	purse_t *tmp = win->purse;
	if (win->evt.type != sfEvtMouseButtonReleased)
		return;
	if (win->evt.mouseButton.button != sfMouseLeft)
		return;
	for (tmp = win->purse; tmp; tmp = tmp->next)
		if (tmp->ver == 1)
			break;
	if (tmp && tmp->ver == 1) {
		detect_click_pickup(tmp, win);
		delet_purse_loot(win);
	}
}
