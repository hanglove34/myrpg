/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** erwann
*/

#include "my.h"

void	fill(node_t **grid, int *origin, map_t *map, monster_t *list_m)
{
	int m = 0;
	for (int i = 0; i < map->height; i++) {
		grid[i] = malloc(sizeof(node_t) * (map->weidth - 1));
		for (int n = 0; n < map->weidth - 1; n++) {
			if (origin[m] == 0)
				grid[i][n].state = 0;
			else
				grid[i][n].state = -1;
			grid[i][n].cost = 0;
			grid[i][n].distance = 0;
			grid[i][n].total = 0;
			grid[i][n].father[0] = 0;
			grid[i][n].father[1] = 0;
			m++;
		}
	}
	fill_posm(list_m, grid, map);
}

void	fill_case(node_t **grid, start_t *list, sfVector2i x, int *pos)
{
	int distance = (x.x + list->end[0]) + (x.y + list->end[1]) + 1;
	if (distance < 0)
		distance *= -1;
	grid[x.y][x.x].cost = grid[pos[1]][pos[0]].cost + 14;
	grid[x.y][x.x].father[0] = pos[0];
	grid[x.y][x.x].father[1] = pos[1];
	grid[x.y][x.x].distance = distance;
	grid[x.y][x.x].total = grid[x.y][x.x].distance + grid[x.y][x.x].cost;
}

void	fill_case_down(node_t **grid, start_t *list, sfVector2i x, int *pos)
{
	int distance = (x.x + list->end[0]) + (x.y + list->end[1]) + 1;
	if (distance < 0)
		distance *= -1;
	grid[x.y][x.x].cost = grid[pos[1]][pos[0]].cost + 10;
	grid[x.y][x.x].father[0] = pos[0];
	grid[x.y][x.x].father[1] = pos[1];
	grid[x.y][x.x].distance = distance;
	grid[x.y][x.x].total = grid[x.y][x.x].distance + grid[x.y][x.x].cost;
}

int	is_in_list(list_t *open_list, list_t *closed_list, int x, int y)
{
	list_t *tmp = open_list;
	list_t *tmp2 = closed_list;
	while (tmp->next != NULL) {
		if (tmp->x == x && tmp->y == y)
			return (1);
		tmp = tmp->next;
	}
	while (tmp2->next != NULL) {
		if (tmp2->x == x && tmp2->y == y)
			return (1);
		tmp2 = tmp2->next;
	}
	return (0);
}

void	find_min(list_t *list, node_t **grid, int *pos)
{
	list_t *tmp = list;
	int n = grid[tmp->y][tmp->x].total;
	pos[0] = tmp->x;
	pos[1] = tmp->y;
	while (tmp->next != NULL) {
		if (tmp->y != -1 && grid[tmp->y][tmp->x].total < n) {
			pos[0] = tmp->x;
			pos[1] = tmp->y;
		}
		tmp = tmp->next;
	}
}
