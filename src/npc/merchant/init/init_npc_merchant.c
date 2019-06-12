/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	init_close_merch(npc_t *new, win_t *win)
{
	new->merch.close = sfSprite_create();
	sfSprite_setTexture(new->merch.close, win->item[1].img, sfTrue);
	sfSprite_setTextureRect(new->merch.close,
	(sfIntRect){15 * 32, 1 * 32, 32, 32});
	sfSprite_setOrigin(new->merch.close, (sfVector2f){16, 16});
	sfSprite_setScale(new->merch.close, (sfVector2f){2, 2});
	sfSprite_setPosition(new->merch.close, (sfVector2f){38, 78});
	sfSprite_setColor(new->merch.close, sfRed);
	new->merch.buy_tex = sfTexture_createFromFile("img/buy.png", NULL);
	new->merch.rect_tex = sfTexture_createFromFile("img/merch.png", NULL);
	new->merch.buy = sfSprite_create();
	sfSprite_setTexture(new->merch.buy, new->merch.buy_tex, sfTrue);
	sfSprite_setOrigin(new->merch.buy, (sfVector2f){75, 25});
	sfSprite_setPosition(new->merch.buy, (sfVector2f){535, 625});
}

void	new_merch_text_stat(npc_t *new, win_t *win)
{
	int i = 0;

	while (i != 8) {
		new->merch.stat[i] = sfText_create();
		sfText_setFont(new->merch.stat[i], win->invent[1].txt.font);
		sfText_setCharacterSize(new->merch.stat[i], 32);
		sfText_setColor(new->merch.stat[i], sfBlack);
		i += 1;
	}
	sfText_setPosition(new->merch.stat[0], (sfVector2f){162, 154});
	sfText_setPosition(new->merch.stat[1], (sfVector2f){325, 154});
	sfText_setPosition(new->merch.stat[2], (sfVector2f){487, 154});
	sfText_setPosition(new->merch.stat[3], (sfVector2f){162, 254});
	sfText_setPosition(new->merch.stat[4], (sfVector2f){325, 254});
	sfText_setPosition(new->merch.stat[5], (sfVector2f){487, 254});
	sfText_setPosition(new->merch.stat[6], (sfVector2f){325, 324});
	sfText_setPosition(new->merch.stat[7], (sfVector2f){385, 605});
}

void	new_merch_pict(npc_t *new, win_t *win)
{
	int i = 0;

	while (i != 7) {
		new->merch.pict[i] = sfSprite_create();
		sfSprite_setTexture(new->merch.pict[i], win->pict[i].img,
		sfTrue);
		sfSprite_setTextureRect(new->merch.pict[i], win->pict[i].rect);
		sfSprite_setScale(new->merch.pict[i], (sfVector2f){1.5, 1.5});
		i += 1;
	}
	sfSprite_setPosition(new->merch.pict[0], (sfVector2f){112, 148});
	sfSprite_setPosition(new->merch.pict[1], (sfVector2f){275, 150});
	sfSprite_setPosition(new->merch.pict[2], (sfVector2f){437, 150});
	sfSprite_setPosition(new->merch.pict[3], (sfVector2f){112, 250});
	sfSprite_setPosition(new->merch.pict[4], (sfVector2f){275, 250});
	sfSprite_setPosition(new->merch.pict[5], (sfVector2f){437, 250});
	sfSprite_setPosition(new->merch.pict[6], (sfVector2f){275, 320});
}

void	new_merch_rect(npc_t *new, win_t *win)
{
	new->merch.rect = sfRectangleShape_create();
	sfRectangleShape_setTexture(new->merch.rect, new->merch.rect_tex,
	sfTrue);
	sfRectangleShape_setSize(new->merch.rect, (sfVector2f){600, 600});
	sfRectangleShape_setPosition(new->merch.rect, (sfVector2f){20, 60});
	new->merch.left_arrow = sfSprite_create();
	sfSprite_setTexture(new->merch.left_arrow, win->item[1].img, sfTrue);
	sfSprite_setTextureRect(new->merch.left_arrow,
	(sfIntRect){1 * 32, 1 * 32, 32, 32});
	sfSprite_setOrigin(new->merch.left_arrow, (sfVector2f){16, 16});
	sfSprite_setScale(new->merch.left_arrow, (sfVector2f){1.5, 1.5});
	sfSprite_setPosition(new->merch.left_arrow, (sfVector2f){55, 485});
	new->merch.right_arrow = sfSprite_create();
	sfSprite_setTexture(new->merch.right_arrow, win->item[1].img, sfTrue);
	sfSprite_setTextureRect(new->merch.right_arrow,
	(sfIntRect){0 * 32, 1 * 32, 32, 32});
	sfSprite_setOrigin(new->merch.right_arrow, (sfVector2f){16, 16});
	sfSprite_setScale(new->merch.right_arrow, (sfVector2f){1.5, 1.5});
	sfSprite_setPosition(new->merch.right_arrow, (sfVector2f){593, 485});
}

void	new_npc_merchant(npc_t *new, win_t *win, char **tab)
{
	new->type = MERCH;

	init_close_merch(new, win);
	new_merch_rect(new, win);
	new_merch_text_stat(new, win);
	new_merch_pict(new, win);
	new->merch.pict[7] = sfSprite_create();
	sfSprite_setTexture(new->merch.pict[7], win->pict[6].img, sfTrue);
	sfSprite_setTextureRect(new->merch.pict[7], win->pict[6].rect);
	sfSprite_setScale(new->merch.pict[7], (sfVector2f){1.5, 1.5});
	sfSprite_setPosition(new->merch.pict[7], (sfVector2f){335, 605});
	new->merch.mouse = sfSprite_create();
	sfSprite_setScale(new->merch.mouse, (sfVector2f){1.5, 1.5});
	new->merch.sum_str = my_strdup("0");
	init_sell_merchant(new, win);
	init_merch_items(new, win, tab);
}
