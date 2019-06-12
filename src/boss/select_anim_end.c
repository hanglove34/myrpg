/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	switch_ater_cine(win_t *win, scene_t *scene)
{
	static int cine = 0;
	if (cine == 57 && win->num_cine == 0)
		switch_scene(win, scene, 90);
	cine = win->num_cine;
}

void	incrase_alpha(win_t *win, int num, int *a, scene_t *scene)
{
	static int mul = 5;
	*a += mul;
	if (*a >= 255) {
		mul = -5;
		if (num == 5)
			place_pnj_act_one(win, scene);
		if (num == 7)
			place_pnj_act_two(win, scene);
	}
}

int	next_act(menu_t *menu, win_t *win, scene_t *scene, int num)
{
	int max = 255;
	static int a = 5;
	menu->clock.time = sfClock_getElapsedTime(menu->clock.clock);
	menu->clock.sec = menu->clock.time.microseconds / 1000000.0;
	sfRenderWindow_drawRectangleShape(win->win,
	win->background[0].rect, NULL);
	if (menu->clock.sec > 0.03) {
		sfRectangleShape_setFillColor(win->background[0].rect,
		sfColor_fromRGBA(0, 0, 0, a));
		incrase_alpha(win, num, &a, scene);
		if (a <= 0) {
			win->state = 0;
			get_cine_num(win, *scene, num);
			sfRectangleShape_setFillColor(win->background[0].rect,
			sfColor_fromRGBA(0, 0, 0, 200));
		}
		menu->offset++;
		sfClock_restart(menu->clock.clock);
	}
}

void	transition_act_one(win_t *win, scene_t *scene)
{
	if (win->state == -3) {
		reset_value(win);
		next_act(&win->menu, win, scene, 5);
	}
	if (win->state == -4) {
		reset_value(win);
		next_act(&win->menu, win, scene, 7);
	}
}

void	check_boss_death(win_t *win, monster_t *tmp)
{
	if (my_strcmp(tmp->monster->name, "boss1\0") == 0 &&
	tmp->monster->stat.xp[0] != 0)
		win->state = -3;
	if (my_strcmp(tmp->monster->name, "ent_boss\0") == 0 &&
	tmp->monster->stat.xp[0] != 0)
		win->state = -4;
}
