/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** thomas
*/

#include "my.h"

sfVector2f	create_spawn(sfVector2f pos, sfVector2i area)
{
	sfVector2f spawn;

	spawn.x = pos.x + rand() % area.x;
	spawn.y = pos.y + rand() % area.y;
	return (spawn);
}

int	random_color_from_percent(int color_percent[3][3],
	int nb, sfColor *color)
{
	int random = 0;
	int i = 0;

	random = rand() % 100;

	while (i < nb) {
		if (color_percent[i][1] >= random &&
		color_percent[i][2] <= random) {
			return (i);
		}
		i++;
	}
	return (0);
}

void	new_particle_next(particle_t *particles_list, p_info_t behavior,
	particle_t *particle)
{
	int i = 0;

	i = random_color_from_percent(behavior.color_percent,
	behavior.nb_color, behavior.color);
	particle->stats.color[0] = behavior.color[i];
	refresh_rect(particle->stats.shape, particle->stats.pos,
	particle->stats.size , particle->stats.color[0]);
	particle->behavior = behavior;
	particle->prev = particles_list;
	particle->next = particles_list->next;
	if (particle->next)
		particle->next->prev = particle;
	particles_list->next = particle;
}

void	new_particle(particle_t *particles_list, p_info_t behavior)
{
	particle_t *particle = malloc(sizeof(*particle));

	particle->stats.states = behavior.states;
	particle->stats.time = behavior.time;
	particle->stats.gravity = behavior.gravity;
	particle->stats.speed = behavior.speed;
	particle->stats.pos = behavior.pos;
	particle->stats.size = behavior.size;
	particle->stats.shape = sfCircleShape_create();
	particle->stats.nb_color = behavior.nb_color;
	particle->stats.color = malloc(sizeof(*behavior.color));
	new_particle_next(particles_list, behavior, particle);
}
