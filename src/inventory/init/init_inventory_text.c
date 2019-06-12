/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	text_init(text_t *text, char *str, sfVector2f pos, int size)
{
	text->txt = sfText_create();
	text->str = str;
	text->size = size;
	text->font = sfFont_createFromFile("img/font_stat.ttf");
	text->pos.x = pos.x;
	text->pos.y = pos.y;
	sfText_setPosition(text->txt, text->pos);
	sfText_setString(text->txt, text->str);
	sfText_setCharacterSize(text->txt, text->size);
	sfText_setColor(text->txt, sfWhite);
	sfText_setFont(text->txt, text->font);
}

void	init_inventory_text(win_t *win)
{
	text_init(&win->invent[1].txt, "HELMET",
	(sfVector2f){win->invent[1].pos.x + 3, win->invent[1].pos.y - 20}, 20);
	text_init(&win->invent[2].txt, "ARMOR",
	(sfVector2f){win->invent[2].pos.x + 10, win->invent[2].pos.y - 20}, 20);
	text_init(&win->invent[3].txt, "WEAPON",
	(sfVector2f){win->invent[3].pos.x + 3, win->invent[3].pos.y - 20}, 20);
	text_init(&win->invent[4].txt, "SHOE",
	(sfVector2f){win->invent[4].pos.x + 15, win->invent[4].pos.y - 20}, 20);
	text_init(&win->invent[5].txt, "SHIELD",
	(sfVector2f){win->invent[5].pos.x, win->invent[5].pos.y - 20}, 20);
}
