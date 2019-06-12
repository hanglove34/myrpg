/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	init_background_inv(rect_shape_t *rect, sfVector2f size,
	sfIntRect color)
{
	rect->size.x = size.x;
	rect->size.y = size.y;
	rect->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(rect->rect, rect->size);
	sfRectangleShape_setFillColor(rect->rect,
	sfColor_fromRGBA(color.left, color.top, color.width, color.height));
}

void	pos_bar_sound(win_t *win)
{
	win->background[10].pos.x = 855;
	win->background[10].pos.y = 200;
	win->background[11].pos.x = 876;
	win->background[11].pos.y = 200;
	win->background[12].pos.x = 897;
	win->background[12].pos.y = 200;
	win->background[13].pos.x = 918;
	win->background[13].pos.y = 200;
	win->background[14].pos.x = 939;
	win->background[14].pos.y = 200;
	sfRectangleShape_setPosition(win->background[10].rect,
	win->background[10].pos);
	sfRectangleShape_setPosition(win->background[11].rect,
	win->background[11].pos);
	sfRectangleShape_setPosition(win->background[12].rect,
	win->background[12].pos);
	sfRectangleShape_setPosition(win->background[13].rect,
	win->background[13].pos);
	sfRectangleShape_setPosition(win->background[14].rect,
	win->background[14].pos);
}

void	pos_rect(win_t *win, rect_shape_t *rect)
{
	init_background_inv(&rect[9], (sfVector2f){400, 500},
	(sfIntRect){40, 122, 255, 255});
	init_background_inv(&rect[10], (sfVector2f){15, -5},
	(sfIntRect){0, 0, 0, 255});
	init_background_inv(&rect[11], (sfVector2f){15, -10},
	(sfIntRect){0, 0, 0, 255});
	init_background_inv(&rect[12], (sfVector2f){15, -15},
	(sfIntRect){0, 0, 0, 255});
	init_background_inv(&rect[13], (sfVector2f){15, -20},
	(sfIntRect){0, 0, 0, 255});
	init_background_inv(&rect[14], (sfVector2f){15, -25},
	(sfIntRect){0, 0, 0, 255});
	init_background_inv(&rect[15], (sfVector2f){WIDTH, HEIGHT},
	(sfIntRect){0, 0, 0, 0});
	win->background = rect;
	sfRectangleShape_setPosition(win->background[6].rect,
	(sfVector2f){200, 200});
	sfRectangleShape_setPosition(win->background[9].rect,
	(sfVector2f){440, 110});
	pos_bar_sound(win);
}

void	init_background(win_t *win)
{
	rect_shape_t *rect = malloc(sizeof(rect_shape_t) * 16);
	init_background_inv(&rect[0], (sfVector2f){WIDTH, HEIGHT},
	(sfIntRect){0, 0, 0, 200});
	init_background_inv(&rect[1], (sfVector2f){100, 120},
	(sfIntRect){115, 51, 7, 255});
	init_background_inv(&rect[2], (sfVector2f){300, 400},
	(sfIntRect){115, 51, 7, 255});
	init_background_inv(&rect[6], (sfVector2f){300, 300},
	(sfIntRect){255, 255, 255, 255});
	sfRectangleShape_setFillColor(rect[6].rect,
	sfColor_fromRGB(245, 222, 179));
	sfRectangleShape_setOutlineThickness(rect[6].rect, 4);
	sfRectangleShape_setOutlineColor(rect[6].rect, sfBlack);
	init_hp_bar(win, rect);
	pos_rect(win, rect);
}
