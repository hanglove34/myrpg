/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	init_case_equip(obj_t *invento)
{
	inits_t mouse = inits_pos_rect(&mouse, (sfVector2f){0, 0},
	(sfIntRect){0, 0, 51, 50}, (sfVector2f){1.5, 1.5});
	invento[0] = *create_object("img/case_select.png", mouse, 1, EMPTY);
	inits_t helmet = inits_pos_rect(&helmet, (sfVector2f){140, 175},
	(sfIntRect){0, 0, 51, 50}, (sfVector2f){1.5, 1.5});
	invento[1] = *create_object("img/case.png", helmet, 1, HELMET);
	inits_t armor = inits_pos_rect(&armor, (sfVector2f){25, 350},
	(sfIntRect){0, 0, 51, 50}, (sfVector2f){1.5, 1.5});
	invento[2] = *create_object("img/case.png", armor, 1, ARMOR);
	inits_t weapon = inits_pos_rect(&weapon, (sfVector2f){275, 300},
	(sfIntRect){0, 0, 51, 50}, (sfVector2f){1.5, 1.5});
	invento[3] = *create_object("img/case.png", weapon, 1, WEAPON);
	inits_t shoe = inits_pos_rect(&shoe, (sfVector2f){140, 500},
	(sfIntRect){0, 0, 51, 50}, (sfVector2f){1.5, 1.5});
	invento[4] = *create_object("img/case.png", shoe, 1, SHOE);
	inits_t shield = inits_pos_rect(&shield, (sfVector2f){275, 400},
	(sfIntRect){0, 0, 51, 50}, (sfVector2f){1.5, 1.5});
	invento[5] = *create_object("img/case.png", shield, 1, SHIELD);
}

void	init_case_stockage(obj_t *inv)
{
	inits_t sto;
	int y = 172.5;
	int x = 900;
	int c = 6;
	int b = 0;
	int d = 0;

	for (; b != 5; b++) {
		for (; d != 5; d++, c++) {
			sto = inits_pos_rect(&sto,
			(sfVector2f){x, y}, (sfIntRect){0, 0, 51, 50},
			(sfVector2f){1.5, 1.5});
			inv[c] = *create_object("img/case.png",
			sto, 1, INV);
			x = x + 72;
		}
		x = 900;
		d = 0;
		y = y + 75;
	}
}

void	init_invent_item(obj_t *invent)
{
	int c = 0;

	while (c != 31) {
		invent[c].state[0] = 0;
		c++;
	}
}

void	init_inv_suit(win_t *win)
{
	obj_t chara;
	obj_t *pict = malloc(sizeof(obj_t) * 7);
	inits_t character = inits_pos_rect(&character, (sfVector2f){50, 200},
	(sfIntRect){128, 0, 128, 155}, (sfVector2f){2, 2});
	chara = *create_object("img/heros.png", character, 1, HERO);
	win->character = chara;
	init_pict_stat(pict);
	win->pict = pict;
	init_liste_item(win);
}

void	init_inventory(win_t *win)
{
	win->ver[0] = 0;
	win->ver[1] = 0;
	win->ver[2] = 0;
	obj_t *invento = malloc(sizeof(obj_t) * 32);
	mouse_t mouse;
	init_inv_suit(win);
	init_case_equip(invento);
	init_case_stockage(invento);
	init_invent_item(invento);
	init_struct_mouse(&mouse);
	init_item(win);
	win->invent = invento;
	win->mouse = mouse;
	init_inventory_text(win);
	init_background(win);
	init_struct_display_stat_heros(win);
}
