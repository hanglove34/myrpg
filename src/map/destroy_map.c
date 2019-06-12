/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

void destroy_int_double_arr(int **arr, map_t *map, int nb)
{
	int count = 0;

	while (count < nb) {
		free(arr[count]);
		count++;
	}
	free(arr);
}

void	destroy_tex(sfTexture **tex, map_t *map)
{
	int i = 0;

	while (i < map->nb_tex) {
		sfTexture_destroy(map->tex[i]);
		i++;
	}
	free(tex);
}

void	destroy_map(map_t *map)
{
	destroy_vertex_arr(map->vtx_arr, map);
	destroy_tex(map->tex, map);
	destroy_int_double_arr(map->map_event, map, map->nb_map_event);
	destroy_int_double_arr(map->sols, map, map->nb_sols);
	destroy_int_double_arr(map->decores, map, map->nb_decores);
	destroy_int_double_arr(map->colisions, map, map->nb_colisions);
	free(map);
}
