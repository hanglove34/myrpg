/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** thomas
*/

#include "my.h"

particle_t	*create_root_particle(void)
{
	particle_t *root = malloc(sizeof(*root));

	root->next = NULL;
	root->prev = NULL;
	return (root);
}

ptcl_contener_t	*create_ptcl_contener_root(void)
{
	ptcl_contener_t *root = malloc(sizeof(*root));

	root->root = NULL;
	root->bool = sfFalse;
	root->fptr = NULL;
	root->next = NULL;
	root->prev = NULL;
	return (root);
}

ptcl_contener_t	*create_ptcl_contener(ptcl_contener_t *root,
	void *manager, void *spawn, cntr_info_t info)
{
	ptcl_contener_t *contener = malloc(sizeof(*contener));
	sfVector2f *pos = info.pos;
	sfBool respawn = info.respawn;
	sfVector2i wave = info.wave;

	contener->prtcl_wave = wave;
	contener->root = create_root_particle();
	contener->bool = sfFalse;
	contener->fptr = manager;
	contener->spawn = spawn;
	contener->pos = pos;
	contener->respawn = respawn;
	contener->next = root->next;
	contener->prev = root;
	if (root->next)
		root->next->prev = contener;
	root->next = contener;
	return (contener);
}

void	refresh_contener(ptcl_contener_t **tmp, ptcl_contener_t **save)
{
	*save = (*tmp)->prev;
	(*tmp)->prev->next = (*tmp)->next;

	if ((*tmp)->next)
		(*tmp)->next->prev = (*tmp)->prev;
	(*tmp) = *save;
}

void	contener_manager(scene_t *scene, win_t *win)
{
	ptcl_contener_t *tmp = scene->particle_manager->root_c->next;
	ptcl_contener_t *save = NULL;
	int i = 0;

	while (tmp && tmp->root) {
		if (tmp->root && tmp->root->next &&
		scene->particle_manager->clock.sec > 0.017) {
			tmp->spawn(tmp, win);
			tmp->fptr(&tmp->root, &tmp->prtcl_wave,
			tmp->respawn, *tmp->pos);
			sfClock_restart(scene->particle_manager->clock.clock);
			if ((tmp->root->next) == NULL) {
				free(tmp->root);
				tmp->root = NULL;
			}
		}
		if (tmp->root == NULL)
			refresh_contener(&tmp, &save);
		tmp = tmp->next;
	}
}
