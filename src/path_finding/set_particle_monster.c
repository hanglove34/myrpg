/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	set_particle_on_monster(monster_t *monster,
	scene_t *scene, win_t *win)
{
	monster_t *tmp = monster;
	p_info_t behavior;

	while (tmp && tmp->next) {
		if (my_strcmp(tmp->monster->name, "boss1") == 0) {
			tmp->monster->cntr = create_ptcl_contener(
			scene->particle_manager->root_c, &manage_dead_particles,
			&spawn_dead_particle, (cntr_info_t){&tmp->monster->pos,
			sfTrue, (sfVector2i){0, 80}});
			behavior = dead_behavior(tmp->monster->pos);
			new_particle(
			scene->particle_manager->root_c->next->root, behavior);
			scene->particle_manager->clock.clock = sfClock_create();
		}
		tmp = tmp->next;
	}
}
