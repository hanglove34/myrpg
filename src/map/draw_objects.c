/*
** EPITECH PROJECT, 2017
** open_a_w
** File description:
** 1st function
*/

#include "my.h"

void	draw_objects_middle_height(scene_t scene, sfRenderWindow *w,
	sfVector2i coord, win_t * win)
{
	sfRenderStates states;
	map_t *map = scene.map;
	int i = coord.x;
	int j = coord.y;
	int n = 0;
	int m = j + 33;

	states.blendMode = sfBlendAlpha;
	states.shader = NULL;
	states.transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	if (scene.map->weidth < 33)
		m = j + scene.map->weidth;
	while (j < m && j < WEIDTH_MAP - 2) {
		n = i * WEIDTH_MAP + j;
		if (map->decores[1][n - i] > 0){
			states.texture = map->tex[map->decores[1][n - i] - 1];
			sfRenderWindow_drawVertexArray(w, MAP_VTX[n], &states);
		}
		j++;
	}
}

void	draw_entities(scene_t scene, sfRenderWindow *w,
	sfVector2i coord, win_t * win)
{
	int i = coord.x;
	int j = coord.y;
	int n = 0;
	entity_t *entity = scene.entity_manager[i]->next;

	while (entity) {
		draw_behind_npc(win, scene.npc);
		entity->draw(entity->type, entity->shape, w);
		entity = entity->next;
	}
}

void	draw_low_height(scene_t scene, sfRenderWindow *w,
	sfVector2i coord, win_t * win)
{
	sfRenderStates states = {.blendMode = sfBlendAlpha, .shader = NULL,
	.transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1)};
	map_t *map = scene.map;
	int n = 0;
	int i = coord.x;
	int j = coord.y;
	int max_width = j + 33;

	if (33 > scene.map->weidth)
		max_width = j + scene.map->weidth;
	while (j < max_width && j < WEIDTH_MAP - 2) {
		n = i * WEIDTH_MAP + j;
		if (j > WEIDTH_MAP - 2)
			return;
		if (map->decores[0][n - i] > 0){
			states.texture = map->tex[map->decores[0][n - i] - 1];
			sfRenderWindow_drawVertexArray(w, MAP_VTX[n], &states);
		}
		j++;
	}
}

void	draw_objects(scene_t scene, sfRenderWindow *w,
	sfVector2i coord, win_t * win)
{
	sfRenderStates states;
	map_t *map = scene.map;
	int n = coord.x * WEIDTH_MAP + coord.y;

	states.blendMode = sfBlendAlpha;
	states.shader = NULL;
	states.transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	draw_low_height(scene, w, coord, win);
	draw_entities(scene, w, coord, win);
	draw_objects_middle_height(scene, w, coord, win);
}
