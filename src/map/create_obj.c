/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

sfVertexArray	**create_vtx_arr_tab(int weidth, int height)
{
	int i = 0;
	int j = 0;
	sfVertexArray **vtx_arr = NULL;
	int size = 0;

	size = weidth * height;
	vtx_arr = malloc(sizeof(*vtx_arr) * size);
	while (i < height) {
		vtx_arr[i * weidth + j] = sfVertexArray_create();
		sfVertexArray_setPrimitiveType(vtx_arr[i * weidth +
		j], sfQuads);
		j++;
		if (j == weidth) {
			j = 0;
			i++;
		}
	}
	return (vtx_arr);
}

map_t	*my_create_map(char *name, win_t *win, pos_map_t info)
{
	map_t *map = NULL;
	sfVector2f pos = info.pos;
	sfVector2f tr = info.tr;

	map = malloc(sizeof(*map));
	if (map == NULL)
		return (NULL);
	map->tr = tr;
	init_all_tileset_and_launch_map_config(map, name, win);
	map->vtx_arr = create_vtx_arr_tab(WEIDTH_MAP, HEIGHT_MAP);
	map->stage = 1;
	map->player_stage = 1;
	map->tr = (sfVector2f){-40, -40};
	refresh_map_vtx_arr(map->vtx_arr, map);
	map->tr = tr;
	win->heros.pos = pos;
	return (map);
}
