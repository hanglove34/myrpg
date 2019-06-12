/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** thomas
*/

#include "my.h"

void	spawn_light_particle(ptcl_contener_t *tmp, win_t *win)
{
	if (tmp->prtcl_wave.x < tmp->prtcl_wave.y) {
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		new_particle(tmp->root, light_behavior(*tmp->pos));
		tmp->prtcl_wave.x += 11;
	}
}

void	refresh_light_particles(sfBool reset, particle_t ***particles,
	sfVector2f pos, particle_t **tmp)
{
	if (reset == sfTrue)
		new_particle(**particles, light_behavior(pos));
	if (**particles)
		kill_particle(*tmp, *particles);
}

void	manage_light_particles(particle_t **particles,
	sfVector2i *prtcl_wave, sfBool reset, sfVector2f pos)
{
	particle_t *tmp = (*particles)->next;
	particle_t *next;

	while (tmp) {
		tmp->stats.time -= 1;
		if (tmp->stats.color[0].a > 3)
			tmp->stats.color[0].a -= 10;
		sfCircleShape_setFillColor(tmp->stats.shape,
		tmp->stats.color[0]);
		tmp->stats.pos.x += tmp->stats.speed.x;
		tmp->stats.pos.y += tmp->stats.speed.y;
		sfCircleShape_setPosition (tmp->stats.shape, tmp->stats.pos);
		next = tmp->next;
		if (tmp->stats.time <= 0)
			refresh_light_particles(reset, &particles, pos, &tmp);
		tmp = next;
	}
}
