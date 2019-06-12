/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg
*/

#include "my.h"

void	set_good_size(win_t *win)
{
	int i[6] = {0, 1, 2, 5, 6, 7};
	int nb = 0;
	for (;nb < 6; nb++) {
		sfText_setCharacterSize(win->menu.button[i[nb]].text, 40);
		sfText_setStyle(win->menu.button[i[nb]].text, sfTextBold);
		sfText_setColor(win->menu.button[i[nb]].text, sfBlack);
	}
}

sfText	*create_text(char *str, sfVector2f pos, win_t *win)
{
	sfText *new;
	new = sfText_create();
	sfText_setString(new, str);
	sfText_setFont(new, win->font);
	sfText_setPosition(new, pos);
	sfText_setColor (new, sfWhite);
	return (new);
}

void button_setting(win_t *win)
{
	inits_t val = inits_pos_rect(&val, (sfVector2f){300, 325},
	(sfIntRect){0, 0, 16, 16}, (sfVector2f){3, 3});
	win->menu.button[2] = *create_object("img/cursor.png", val, 10, BUTTON);
	win->menu.button[2].text = create_text("SETTINGS",
	(sfVector2f){380, 331}, win);
	win->menu.button[2].ptr_cmd = &settings_button;
	sfText_setScale (win->menu.button[2].text, (sfVector2f){0.7, 0.7});
	val = inits_pos_rect(&val, (sfVector2f){940, 170},
	(sfIntRect){0, 0, 512,512}, (sfVector2f){0.08, 0.08});
	win->menu.button[3] = *create_object("img/add.png", val, 10, BUTTON);
	win->menu.button[3].ptr_cmd = &up_music;
	val = inits_pos_rect(&val, (sfVector2f){800, 170},
	(sfIntRect){0, 0, 512,512}, (sfVector2f){0.08, 0.08});
	win->menu.button[4] = *create_object("img/less.png", val, 10, BUTTON);
	win->menu.button[4].ptr_cmd = &less_music;
	init_button_menu(win);
}

void	create_button(win_t *win)
{
	inits_t val = inits_pos_rect(&val, (sfVector2f){300, 125},
	(sfIntRect){0, 0, 16, 16}, (sfVector2f){3, 3});
	win->menu.button[0] = *create_object("img/cursor.png", val, 10, BUTTON);
	win->menu.button[0].text = create_text("PLAY",
	(sfVector2f){380, 131}, win);
	win->menu.button[0].ptr_cmd = &play_button;
	win->menu.button[0].reset = &reset_game;
	sfText_setScale (win->menu.button[0].text, (sfVector2f){0.7, 0.7});
	val = inits_pos_rect(&val, (sfVector2f){300, 525},
	(sfIntRect){0, 0, 16, 16}, (sfVector2f){3, 3});
	win->menu.button[1] = *create_object("img/cursor.png", val, 10, BUTTON);
	win->menu.button[1].text = create_text("EXIT",
	(sfVector2f){380, 531}, win);
	win->menu.button[1].ptr_cmd = &exit_button;
	sfText_setScale (win->menu.button[1].text, (sfVector2f){0.7, 0.7});
	button_setting(win);
	set_good_size(win);
}

void	create_menu(win_t *win)
{
	win->font = sfFont_createFromFile("img/font.ttf");
	win->menu.spt = sfSprite_create();
	win->menu.speed = 6;
	win->menu.img = sfTexture_createFromFile("img/bg.png", NULL);
	win->menu.rect = (sfIntRect){0, 0, 1280, 720};
	win->menu.pos.x = 0;
	win->menu.pos.y = 0;
	win->menu.offset = 0;
	win->menu.clock.clock = sfClock_create();
	sfSprite_setPosition(win->menu.spt, win->menu.pos);
	sfSprite_setTextureRect(win->menu.spt, win->menu.rect);
	win->menu.text = sfText_create();
	sfSprite_setTexture(win->menu.spt, win->menu.img, sfTrue);
	sfText_setString(win->menu.text, "Press any key");
	sfText_setFont(win->menu.text, win->font);
	sfText_setCharacterSize(win->menu.text, 50);
	sfText_setColor(win->menu.text, sfBlack);
	sfText_setPosition(win->menu.text, (sfVector2f){520, 20});
	create_button(win);
}
