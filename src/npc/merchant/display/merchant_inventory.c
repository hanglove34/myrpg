/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	reset_pos_invent_merch(win_t *win)
{
	sfSprite_setPosition(win->invent[1].spt, (sfVector2f){140, 175});
	win->invent[1].pos = (sfVector2f){140, 175};
	sfSprite_setPosition(win->invent[2].spt, (sfVector2f){25, 350});
	win->invent[2].pos = (sfVector2f){25, 350};
	sfSprite_setPosition(win->invent[3].spt, (sfVector2f){275, 300});
	win->invent[3].pos = (sfVector2f){275, 300};
	sfSprite_setPosition(win->invent[4].spt, (sfVector2f){140, 500});
	win->invent[4].pos = (sfVector2f){140, 500};
	sfSprite_setPosition(win->invent[5].spt, (sfVector2f){275, 400});
	win->invent[5].pos = (sfVector2f){275, 400};
}

void	reset_pos_text_invent_merch(win_t *win)
{
	win->invent[1].txt.pos = (sfVector2f){win->invent[1].pos.x
	+ 3, win->invent[1].pos.y - 20};
	sfText_setPosition(win->invent[1].txt.txt, win->invent[1].txt.pos);
	win->invent[2].txt.pos = (sfVector2f){win->invent[2].pos.x
	+ 10, win->invent[2].pos.y - 20};
	sfText_setPosition(win->invent[2].txt.txt, win->invent[2].txt.pos);
	win->invent[3].txt.pos = (sfVector2f){win->invent[3].pos.x
	+ 3, win->invent[3].pos.y - 20};
	sfText_setPosition(win->invent[3].txt.txt, win->invent[3].txt.pos);
	win->invent[4].txt.pos = (sfVector2f){win->invent[4].pos.x
	+ 15, win->invent[4].pos.y - 20};
	sfText_setPosition(win->invent[4].txt.txt, win->invent[4].txt.pos);
	win->invent[5].txt.pos = (sfVector2f){win->invent[5].pos.x
	+ 5, win->invent[5].pos.y - 20};
	sfText_setPosition(win->invent[5].txt.txt, win->invent[5].txt.pos);
}

void	restore_invent_merch(win_t *win)
{
	int y = 172.5;
	int x = 900;
	int i = 6;

	reset_pos_invent_merch(win);
	reset_pos_text_invent_merch(win);
	for (int j = 0; j != 5; j++) {
		for (int k = 0; k != 5; k++, i++) {
			sfSprite_setPosition(win->invent[i].spt,
			(sfVector2f){x, y});
			x += 72;
		}
		x = 900;
		y += 75;
	}
}

void	change_select_merch_case(sfVector2i pos, obj_t *square, win_t *win,
	int nb)
{
	if ((pos.x > square->pos.x && pos.x < (square->pos.x + 72))
	&& (pos.y > square->pos.y && pos.y < (square->pos.y + 75))) {
		sfSprite_setTexture(square->spt, win->invent[0].img, sfTrue);
		display_stat_item(win, nb);
	}
	else
		sfSprite_setTexture(square->spt, win->invent[1].img, sfTrue);
}

void	merch_inventory_handling(win_t *win)
{
	int i = 1;
	sfVector2i pos = sfMouse_getPositionRenderWindow(win->win);

	while (i != 31) {
		change_select_merch_case(pos, &win->invent[i], win, i);
		i++;
	}
}
