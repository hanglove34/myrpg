/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

entity_t	*create_root_entity(void)
{
	entity_t *root = malloc(sizeof(*root));

	root->x = 0;
	root->y = 0;
	root->priority = 0;
	root->type = NONE;
	root->shape = NULL;
	root->draw = NULL;
	root->next = NULL;
	root->prev = NULL;
}

entity_t **create_entity_manager(int size)
{
	entity_t **manager = malloc(sizeof(*manager) * (size + 1));
	int i = 0;

	while (i < size) {
		manager[i] = create_root_entity();
		i++;
	}
	manager[size] = NULL;
	return (manager);
}

entity_t	*create_entity(sfVector2f pos, DrawType type,
	void *shape, int prio)
{
	entity_t *entity = malloc(sizeof(*entity));

	entity->x = (int)pos.x;
	entity->y = (int)pos.y;
	entity->real_pos = pos;
	entity->priority = prio;
	entity->type = type;
	entity->shape = shape;
	entity->draw = &draw_entity;
	entity->next = NULL;
	entity->prev = NULL;
	return (entity);
}
