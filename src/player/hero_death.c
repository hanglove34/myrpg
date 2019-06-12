/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	increase_lum(win_anim_t *info,
	win_t *win)
{
	clck_t clck = info->clock;

	while (info->color.a < 0xff && info->color.b < 0xff) {
		if (sfRenderWindow_pollEvent(win->win, &win->evt) &&
		win->evt.type == sfEvtClosed)
			sfRenderWindow_close(win->win);
		sfRenderWindow_clear(win->win, sfBlack);
		clck.time = sfClock_getElapsedTime(clck.clock);
		clck.sec = clck.time.microseconds / 1000000.0;
		if (clck.sec >= 0.01) {
			decrease_red_color(&info->color, 1, sfTrue, 1);
			sfRectangleShape_setFillColor(info->shp, info->color);
			sfClock_restart(clck.clock);
		}
		sfRenderWindow_drawRectangleShape(win->win, info->shp, NULL);
		sfRenderWindow_display(win->win);
	}
	sfRenderWindow_drawRectangleShape(win->win, info->shp, NULL);
	sfRenderWindow_display(win->win);
}

void	decrease_lum(win_anim_t *info,
	win_t *win)
{
	clck_t clck = info->clock;

	while (info->color.a > 0) {
		if (sfRenderWindow_pollEvent(win->win, &win->evt) &&
		win->evt.type == sfEvtClosed)
			sfRenderWindow_close(win->win);
		sfRenderWindow_clear(win->win, sfBlack);
		clck.time = sfClock_getElapsedTime(clck.clock);
		clck.sec = clck.time.microseconds / 1000000.0;
		if (clck.sec >= 0.01) {
			info->color.a -= 1;
			sfRectangleShape_setFillColor(info->shp, info->color);
			sfClock_restart(clck.clock);
		}
		sfRenderWindow_drawRectangleShape(win->win, info->shp, NULL);
		sfRenderWindow_display(win->win);
	}
}

void	print_dead_message(win_anim_t *info,
	win_t *win)
{
	clck_t clck = info->clock;
	sfText *text = info->text;

	while (info->centiseconds < 200) {
		if (sfRenderWindow_pollEvent(win->win, &win->evt) &&
		win->evt.type == sfEvtClosed)
			sfRenderWindow_close(win->win);
		sfRenderWindow_clear(win->win, sfBlack);
		clck.time = sfClock_getElapsedTime(clck.clock);
		clck.sec = clck.time.microseconds / 1000000.0;
		if (clck.sec >= 0.01) {
			info->centiseconds += 1;
			sfClock_restart(clck.clock);
		}
		sfRenderWindow_drawRectangleShape(win->win, info->shp, NULL);
		sfRenderWindow_drawText(win->win, text, NULL);
		sfRenderWindow_display(win->win);
	}
}

void	hero_death_respawn(win_t *win, scene_t *scene,
	win_anim_t *new)
{
	win_anim_t info = *new;

	load(scene, win);
	sfRenderWindow_clear(win->win, sfBlack);
	refresh_map_vtx_arr(scene[win->scene].map->vtx_arr,
	scene[win->scene].map);
	my_draw_window(win->win, scene[win->scene].map, win,
	scene[win->scene]);
	info.img = sfRenderWindow_capture(win->win);
	sfTexture_updateFromImage(info.texture, info.img, 0, 0);
	sfRectangleShape_setTexture(info.shp, info.texture, sfTrue);
	increase_lum(&info, win);
}

void	hero_death(win_t *win, scene_t *scene)
{
	win_anim_t info = create_hero_death_struct(win);

	refresh_rectangle(info.shp, (sfVector2f){0, 0},
	(sfVector2f) {WIDTH, HEIGHT}, info.color);
	sfRectangleShape_setTexture(info.shp, info.texture, sfTrue);
	decrease_lum(&info, win);
	print_dead_message(&info, win);
	hero_death_respawn(win, scene,
	&info);
}
