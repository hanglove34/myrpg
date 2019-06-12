/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	add_entity(entity_t *entity, entity_t *list)
{
	entity_t *tmp = list->next;

	if (!tmp) {
		list->next = entity;
		entity->next = NULL;
		entity->prev = list;
		return;
	}
	while (tmp && tmp->next && entity->real_pos.y > tmp->real_pos.y)
		tmp = tmp->next;
	if (!tmp->next && entity->real_pos.y > tmp->real_pos.y) {
		entity->prev = tmp;
		entity->next = NULL;
		tmp->next = entity;
		return;
	}
	entity->next = tmp;
	entity->prev = tmp->prev;
	tmp->prev->next = entity;
	tmp->prev = entity;
}

void	remove_entity(entity_t *entity, entity_t *list)
{
	if (entity->prev == list) {
		if (entity->next == NULL) {
			list->next = NULL;
		} else {
			list->next = entity->next;
			entity->next->prev = list;
		}
	} else if (!entity->next) {
		entity->prev->next = NULL;
	} else {
		entity->next->prev = entity->prev;
		entity->prev->next = entity->next;
	}
}

void	kill_entity(entity_t *entity, monster_t *tmp)
{
	if (tmp && tmp->monster && tmp->monster->cntr &&
	my_strncmp(tmp->monster->name, "boss", 4) == 0)
		tmp->monster->cntr->respawn = sfFalse;
	free(entity);
	entity = NULL;
}

void	draw_entity(DrawType type, void *shape, sfRenderWindow *w)
{
	sfRenderWindow_drawSprite(w, (sfSprite *)shape, NULL);
	return;
}
