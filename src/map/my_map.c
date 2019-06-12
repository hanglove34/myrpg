/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

void	destroy_vertex_arr(sfVertexArray **vtx_arr, map_t *map)
{
	int i = 0;
	int j = 0;

	while (i < HEIGHT_MAP - 1) {
		sfVertexArray_destroy(vtx_arr[i * WEIDTH_MAP + j]);
		j++;
		if (j == WEIDTH_MAP - 1) {
			j = 0;
			i++;
		}
	}
}

myquad_t init_quad(int i, int j, map_t *map)
{
	sfVector2f tr = (sfVector2f)map->tr;
	int s = SCALE_MAP;

	return ((myquad_t){(sfVector2f){j * s + tr.x, i * s + tr.y},
		(sfVector2f){j * s + tr.x, (i + 1) * s + tr.y},
		(sfVector2f){(j + 1) * s + tr.x, (i + 1) * s + tr.y},
		(sfVector2f){(j + 1) * s + tr.x, i * s + tr.y}
	});
}

void	refresh_quad(myquad_t quad, sfColor color,
	sfVertexArray *vertex_array)
{
	sfVertex vertex1 = {quad.p1, color, (sfVector2f){0, 0}};
	sfVertex vertex2 = {quad.p2, color, (sfVector2f){0, 16}};
	sfVertex vertex3 = {quad.p3, color, (sfVector2f){16, 16}};
	sfVertex vertex4 = {quad.p4, color, (sfVector2f){16, 0}};

	sfVertexArray_clear(vertex_array);
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_append(vertex_array, vertex3);
	sfVertexArray_append(vertex_array, vertex4);
}

void	refresh_map_vtx_arr(sfVertexArray **vtx_arr, map_t *map)
{
	myquad_t quad;
	sfColor color = sfColor_fromRGBA(255, 255, 255, 255);
	sfVector2f tr = (sfVector2f)map->tr;
	sfVector2f start = {-map->tr.x / SCALE_MAP, -map->tr.y / SCALE_MAP};
	int max_height = start.y + 19;
	int max_width = start.x + 33;
	int i = start.y;
	int j = start.x;

	while (i < HEIGHT_MAP - 1 ) {
		if (i < max_height && j < max_width){
			quad = init_quad(i, j, map);
			refresh_quad(quad, color, vtx_arr[i * WEIDTH_MAP + j]);
		}
		j++;
		if (j == WEIDTH_MAP - 1) {
			j = 0;
			i++;
		}
	}
}
