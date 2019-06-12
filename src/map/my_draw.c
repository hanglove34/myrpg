/*
** EPITECH PROJECT, 2017
** open_a_w
** File description:
** 1st function
*/

#include "my.h"

void	draw_map_ground(map_t *map, sfRenderWindow *w,
	win_t * win, sfVector2i info)
{
	sfRenderStates states;
	int i = info.x;
	int index = info.y;

	states.blendMode = sfBlendAlpha;
	states.shader = NULL;
	states.transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
	if (map->sols[map->stage][index - i] >= 1) {
		states.texture = map->tex[map->sols[map->stage][index - i] - 1];
		sfRenderWindow_drawVertexArray(w, MAP_VTX[index], &states);
	}
}

void	draw_ground(scene_t scene, sfRenderWindow *w,
	win_t *win, sfVector2f start)
{
	int i = start.y;
	int j = start.x;
	int m = i + 19;
	int n = j + 33;
	int index = 0;

	m = (m > scene.map->height - 1) ? scene.map->height - 1 : m;
	n = (n > scene.map->weidth - 1) ? scene.map->weidth - 1 : n;
	while (i < m) {
		if (j != scene.WEIDTH_MAP - 1) {
			index = i * scene.WEIDTH_MAP + j;
			draw_map_ground(scene.map, w, win,
			(sfVector2i){i, index});
		}
		j++;
		if (j == n) {
			j = 0;
			i++;
		}
	}
}

void	draw_map_vtx_arr(scene_t scene, sfRenderWindow *w,
	win_t *win, sfVector2f start)
{
	int i = start.y;
	int j = start.x;
	int max_height = i + 19;
	int max_width = j + 33;
	int index = 0;

	draw_ground(scene, w, win, start);
	display_loot(win->purse, win);
	while (i < max_height && i < scene.map->height - 1) {
		draw_objects(scene, w, (sfVector2i){i, j}, win);
		i++;
	}
	scene.map->stage = 1;
	draw_ground(scene, w, win, start);
}

void	my_draw_window(sfRenderWindow *w, map_t *map,
	win_t *win, scene_t scene)
{
	sfVector2f start = {-map->tr.x / SCALE_MAP, -map->tr.y / SCALE_MAP};

	scene.map->stage = 0;
	draw_map_vtx_arr(scene, w, win, start);
	draw_front_npc(win, scene.npc);
	display_npc_pict(scene.npc, win);
	map->stage = 0;
}
