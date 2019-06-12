/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** thomas
*/

#include "my.h"

void	draw_particles(ptcl_contener_t *root, sfRenderWindow *window)
{
	ptcl_contener_t *tmp2 = root->next;
	particle_t *tmp = NULL;

	while (tmp2) {
		tmp = tmp2->root->next;
		while (tmp) {
			sfRenderWindow_drawCircleShape(window,
			tmp->stats.shape, NULL);
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}

void	refresh_rect(sfCircleShape *shp, sfVector2f pos,
	sfVector2f sz, sfColor c)
{
	sfCircleShape_setRadius(shp, sz.x);
	sfCircleShape_setPosition(shp, pos);
	sfCircleShape_setFillColor(shp, c);
}

void	kill_particle(particle_t *particle, particle_t **real)
{
	if (particle->prev) {
		if (particle->next) {
			particle->prev->next = particle->next;
		}
		else
			particle->prev->next = NULL;
	}
	else {
		*real = particle->next;
		if (particle->next)
			particle->next->prev = NULL;
	}
	if (particle->next)
		particle->next->prev = particle->prev;
	sfCircleShape_destroy(particle->stats.shape);
	free(particle->behavior.color);
	free(particle->stats.color);
	free(particle);
}

int	particles_manager(scene_t *scene, win_t *win)
{
	if (!scene->particle_manager->root_c->next)
		return (0);
	PTCL_MNG_CLOCK_TIME = sfClock_getElapsedTime(PTCL_MNG_CLOCK);
	PTCL_MNG_CLOCK_SEC = PTCL_MNG_CLOCK_MICRO / 1000000.0;
	contener_manager(scene, win);
	if (!scene->particle_manager->root_c->next) {
		sfClock_destroy(PTCL_MNG_CLOCK);
	}
	return (0);
}
