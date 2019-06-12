/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

int	move_type_x(win_t *win, map_t *map, int offset)
{
	int x = win->heros.pos.x - map->tr.x + offset;
	int x2 = x / SCALE_MAP;
	int x3 = (x - offset) / SCALE_MAP;

	if (x2 <= 17) {
		return (1);
	}
	if (x2 == 18 && x3 == 17)
		win->heros.pos.x += offset;
	if (x2 >= (map->weidth - 17)) {
		return (1);
	}
	if (x2 == map->weidth - 18 && x3 == map->weidth - 17)
		win->heros.pos.x += offset;
	return (0);
}

int	move_type_y(win_t *win, map_t *map, int offset)
{
	int y = win->heros.pos.y - map->tr.y + offset;
	int y2 = y / SCALE_MAP;
	int y3 = (y - offset) / SCALE_MAP;

	if (y2 <= 9) {
		return (1);
	}
	if (y2 == 10 && y3 == 9)
		win->heros.pos.y += offset;
	if (y2 >= (map->height - 11)) {
		return (1);
	}
	if (y2 == map->height - 12 && y3 == map->height - 11)
		win->heros.pos.y += offset;
	return (0);
}
