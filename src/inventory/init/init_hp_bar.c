/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	init_xp_bar(win_t *win, rect_shape_t *rect)
{
	init_background_inv(&rect[7], (sfVector2f){355, 20},
	(sfIntRect){255, 255, 255, 180});
	rect[7].pos = (sfVector2f){92, 55};
	sfRectangleShape_setPosition(rect[7].rect, rect[7].pos);
	init_background_inv(&rect[8], (sfVector2f){0, 20},
	(sfIntRect){179, 0, 255, 180});
	rect[8].pos = (sfVector2f){92, 55};
	sfRectangleShape_setPosition(rect[8].rect, rect[8].pos);
	win->hp_tex = sfTexture_createFromFile("img/hp.png", NULL);
	win->hp_spr = sfSprite_create();
	sfSprite_setTexture(win->hp_spr, win->hp_tex, sfTrue);
	sfSprite_setPosition(win->hp_spr, (sfVector2f){10, 10});
}

void	init_hp_bar(win_t *win, rect_shape_t *rect)
{
	init_background_inv(&rect[4], (sfVector2f){370, 20},
	(sfIntRect){255, 255, 255, 180});
	rect[4].pos = (sfVector2f){92, 35};
	sfRectangleShape_setPosition(rect[4].rect, rect[4].pos);
	init_background_inv(&rect[5], (sfVector2f){370, 20},
	(sfIntRect){255, 0, 0, 180});
	rect[5].pos = (sfVector2f){92, 35};
	sfRectangleShape_setPosition(rect[5].rect, rect[5].pos);
	init_xp_bar(win, rect);
}
