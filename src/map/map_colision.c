/*
** EPITECH PROJECT, 2017
** open_a_window
** File description:
** 1st function
*/

#include "my.h"

int	in_map(sfVector2f w_coord, sfVector2f offset, map_t *map)
{
	sfVector2i test;
	int x = w_coord.x + offset.x - map->tr.x;
	int y = w_coord.y + offset.y - map->tr.y;

	if (x < 0 || y < 0)
		return (0);
	test = (sfVector2i){(x / SCALE_MAP), (y / SCALE_MAP)};
	if (test.x < map->weidth - 1 && test.y < map->height - 1)
		return (1);
	return (0);
}

int behind_case(map_t *map, win_t *win)
{
	if ((test_colision((sfVector2f){win->heros.pos.x, win->heros.pos.y},
	(sfVector2f){-15, -win->heros.speed}, map) > 0) ||
	test_colision((sfVector2f){win->heros.pos.x, win->heros.pos.y},
	(sfVector2f){14, -win->heros.speed}, map) > 0)
		return (1);
	return (0);
}

int forward_case(map_t *map, win_t *win)
{
	if ((test_colision((sfVector2f){win->heros.pos.x, win->heros.pos.y},
	(sfVector2f){-15, win->heros.speed}, map) > 0) ||
	test_colision((sfVector2f){win->heros.pos.x, win->heros.pos.y},
	(sfVector2f){14, win->heros.speed}, map) > 0)
		return (1);
	return (0);
}

int	test_colision_around_character(map_t *map, win_t *win, int index)
{
	switch (index) {
		case 1 :
			if (behind_case(map, win))
				return (1);
			break;
		case 0 :
			if (forward_case(map, win))
				return (1);
			break;
		default:
			return (0);
		}
	return (0);
}

int	test_colision(sfVector2f w_coord, sfVector2f offset, map_t *map)
{
	sfVector2i coord = ((sfVector2i){(w_coord.x + offset.x - map->tr.x)
	/ SCALE_MAP, (w_coord.y + offset.y - map->tr.y)
	/ SCALE_MAP});
	int n = (coord.y) * (WEIDTH_MAP - 1) + coord.x;

	return (map->colisions[0][n]);
}
