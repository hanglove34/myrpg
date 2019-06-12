/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	destroy_entity_manager(scene_t scene)
{
	int i = 0;

	while (i < scene.map->height - 1) {
		i++;
	}
	free(scene.entity_manager);
}

void	destroy_scene(scene_t scene)
{
	destroy_entity_manager(scene);
	destroy_map(scene.map);
}

void	destroy_scenes(scene_t *scenes, int nb)
{
	int i = 0;

	while (i < nb) {
		destroy_scene(scenes[i]);
		i++;
	}
	free(scenes);
}
