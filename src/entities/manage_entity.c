/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	manage_entity_after(win_t *win, scene_t *scene)
{
	monster_t *tmp = scene->monster;
	entity_t *entity = NULL;

	if (!tmp || !tmp->monster)
		return;
	while (tmp && tmp->next) {
		if (!tmp->monster->entity) {
			tmp = tmp->next;
			continue;
		}
		entity = tmp->monster->entity;
		entity->x = tmp->monster->pos.x - scene->map->tr.x;
		remove_entity(entity,
		scene->entity_manager[(int)entity->real_pos.y / 40]);
		kill_entity(entity, NULL);
		tmp->monster->entity = NULL;
		tmp = tmp->next;
	}
}

void	manage_entity(win_t *win, scene_t *scene)
{
	monster_t *tmp = scene->monster;
	entity_t *entity = NULL;
	sfVector2f real_pos;

	if (!tmp || !tmp->monster)
		return;
	while (tmp && tmp->next) {
		real_pos = (sfVector2f){tmp->monster->pos.x - scene->map->tr.x,
		tmp->monster->pos.y - scene->map->tr.y};
		entity = create_entity(real_pos, SPRITE, tmp->monster->spt, 0);
		add_entity(entity, scene->entity_manager[(int)real_pos.y / 40]);
		if (tmp->monster->stat.hp <= 0) {
			remove_entity(entity,
			scene->entity_manager[(int)real_pos.y / 40]);
			kill_entity(entity, tmp);
			entity = NULL;
		}
		tmp->monster->entity = entity;
		tmp = tmp->next;
	}
}
