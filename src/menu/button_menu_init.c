/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg
*/

#include "my.h"

sfText	*create_text_settings(char *str, sfVector2f pos, win_t *win)
{
	sfFont *font = sfFont_createFromFile("img/font_stat.ttf");
	sfText *new;
	new = sfText_create();
	sfText_setString(new, str);
	sfText_setFont(new, font);
	sfText_setPosition(new, pos);
	sfText_setColor (new, sfWhite);
	return (new);
}

void	change_style_text(win_t *win, int i)
{
	sfText_setCharacterSize(win->menu.button[i].text, 40);
	sfText_setStyle(win->menu.button[i].text, sfTextUnderlined);
	sfText_setColor(win->menu.button[i].text, sfBlack);
}

void	luminosity(win_t *win)
{
	win->menu.button[9].text = create_text_settings("Luminosity",
	(sfVector2f){810, 210}, win);
	sfText_setScale (win->menu.button[9].text, (sfVector2f){0.7, 0.7});
	change_style_text(win, 9);
	inits_t val = inits_pos_rect(&val, (sfVector2f){950, 250},
	(sfIntRect){0, 0, 512, 512}, (sfVector2f){0.08, 0.08});
	win->menu.button[10] = *create_object("img/add.png", val, 10, BUTTON);
	win->menu.button[10].ptr_cmd = &luminosity_add;
	val = inits_pos_rect(&val, (sfVector2f){790, 250},
	(sfIntRect){0, 0, 512, 512}, (sfVector2f){0.08, 0.08});
	win->menu.button[11] = *create_object("img/less.png", val, 10, BUTTON);
	win->menu.button[11].ptr_cmd = &luminosity_less;
}

void	init_button_menu_suit(win_t *win)
{
	inits_t val = inits_pos_rect(&val, (sfVector2f){300, 225},
	(sfIntRect){0, 0, 16, 16}, (sfVector2f){3, 3});
	win->menu.button[7] = *create_object("img/cursor.png", val, 10,
	BUTTON);
	win->menu.button[7].text = create_text("CONTINUE",
	(sfVector2f){380, 231}, win);
	win->menu.button[7].ptr_cmd = &continue_the_game;
	sfText_setScale (win->menu.button[7].text, (sfVector2f){0.7, 0.7});
	win->menu.button[8].text = create_text_settings("Sound",
	(sfVector2f){850, 135}, win);
	sfText_setScale (win->menu.button[8].text, (sfVector2f){0.7, 0.7});
	change_style_text(win, 8);
	luminosity(win);
}

void	init_button_menu(win_t *win)
{
	inits_t val = inits_pos_rect(&val, (sfVector2f){300, 425},
	(sfIntRect){0, 0, 16, 16}, (sfVector2f){3, 3});
	win->menu.button[5] = *create_object("img/cursor.png", val, 10, BUTTON);
	win->menu.button[5].text = create_text("CREDIT",
	(sfVector2f){380, 431}, win);
	win->menu.button[5].ptr_cmd = &credit;
	sfText_setScale (win->menu.button[5].text, (sfVector2f){0.7, 0.7});
	val = inits_pos_rect(&val, (sfVector2f){300, 400},
	(sfIntRect){0, 0, 16, 16}, (sfVector2f){3, 3});
	win->menu.button[6] = *create_object("img/cursor.png", val, 10, BUTTON);
	win->menu.button[6].text = create_text("MAIN MENU",
	(sfVector2f){380, 406}, win);
	win->menu.button[6].ptr_cmd = &back_to_the_menu;
	sfText_setScale (win->menu.button[6].text, (sfVector2f){0.7, 0.7});
	init_button_menu_suit(win);
}
