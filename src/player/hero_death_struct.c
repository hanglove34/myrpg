/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

sfText	*create_dead_text(win_t *win)
{
	sfVector2f pos = {470, HEIGHT / 2 - 50};
	sfText *text = create_text("YOU ARE DEAD !",
	pos, win);

	sfText_setCharacterSize(text, 50);
	sfText_setColor(text, sfColor_fromRGBA(0x8B, 0x00, 0x00, 200));
	return (text);
}

void	destroy_hero_death_struc(win_anim_t *info)
{
	if (info->init == 0)
		return;
	sfRectangleShape_destroy(info->shp);
	sfImage_destroy(info->img);
	sfTexture_destroy(info->texture);
	sfText_destroy(info->text);
	sfClock_destroy(info->clock.clock);
}

win_anim_t create_hero_death_struct(win_t *win)
{
	win_anim_t info = win->info;

	info.img = sfRenderWindow_capture(win->win);
	info.area = (sfIntRect){0, 0, WIDTH, HEIGHT};
	if  (win->info.init == 0) {
		info.init = 1;
		info.clock.clock = sfClock_create();
		info.shp = sfRectangleShape_create();
		info.text = create_dead_text(win);
		info.texture = sfTexture_createFromImage(info.img, &info.area);
	}
	else {
		sfTexture_updateFromImage(info.texture, info.img, 0, 0);
	}
	info.color = sfColor_fromRGBA(0x8B, 0x00, 0x00, 200);
	info.centiseconds = 0;
	win->info = info;
	return (info);
}
