/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

int	test_event(win_t *win, map_t *map, sfVector2f dv)
{
	int x = win->heros.pos.x - map->tr.x;
	int y =  win->heros.pos.y - map->tr.y;
	int x_dv = x + dv.x;
	int y_dv = y + dv.y;
	int x_scale = x_dv / SCALE_MAP;
	int y_scale = y_dv / SCALE_MAP;
	int x2 = x / SCALE_MAP;
	int y2 = y /SCALE_MAP;
	int w = WEIDTH_MAP - 1;

	if (in_map((sfVector2f){win->heros.pos.x, win->heros.pos.y},
	(sfVector2f){0, win->heros.speed}, map) == 0)
		return (0);
	if (map->map_event[0][y_scale * w + x_scale] != -1)
		if (map->map_event[0][y2 * w + x2] == -1)
			map->event = map->map_event[0][y_scale * w + x_scale];
	return (0);
}
