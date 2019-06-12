/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	change_xp_bar(win_t *win)
{
	float percent = (float)win->heros.stat.xp[0] /
	(float)win->heros.stat.xp[1];
	float ref = 355 * percent;
	sfVector2f size = {ref, 20};
	sfRectangleShape_setSize(win->background[8].rect, size);
	sfRenderWindow_drawRectangleShape(win->win,
	win->background[8].rect, NULL);
}

void	add_xp(win_t *win, monster_t *tmp)
{
	int *item;
	if (tmp->monster->stat.hp <= 0) {
		win->heros.stat.xp[0] += tmp->monster->stat.xp[0];
		check_boss_death(win, tmp);
		tmp->monster->stat.xp[0] = 0;
		change_xp_bar(win);
		item = gene_item(win);
		insertion_loot(win, win->scene,
		(sfVector2f){tmp->monster->pos.x, tmp->monster->pos.y}, item);
	}
}

void	up_stat(win_t *win)
{
	win->heros.stat.atk += 1;
	win->heros.stat.armor += 1;
	win->heros.stat.hp += 4;
	win->heros.stat.lvl += 1;
	change_stat_item_heros(win);
}

void	level_up(win_t *win, scene_t *scene)
{
	if (win->heros.stat.xp[0] >= win->heros.stat.xp[1]) {
		win->heros.stat.xp[0] = 0;
		win->heros.stat.xp[1] *= 1.5;
		change_xp_bar(win);
		create_ptcl_contener(scene[win->scene].particle_manager->root_c,
		&manage_light_particles, &spawn_light_particle,
		(cntr_info_t){&win->heros.pos, sfFalse, (sfVector2i){0, 300}});
		new_particle(
		scene[win->scene].particle_manager->root_c->next->root,
		light_behavior(win->heros.pos));
		scene[win->scene].particle_manager->clock.clock =
		sfClock_create();
		up_stat(win);
	}
}
