/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	free_path(list_t *list)
{
	list_t *p_temp = list;
	while (p_temp->next != NULL) {
		list_t *p_del = p_temp;
		p_temp = p_temp->next;
		free(p_del);
	}
}

void	init_path(int *pos, start_t *list, node_t **grid)
{
	pos[0] = list->start[0];
	pos[1] = list->start[0];
	grid[list->end[1]][list->end[0]].state = 3;
	grid[list->start[1]][list->start[0]].state = 2;
	add_openlist(list, list->start[0], list->start[1]);
}

int	block_path_finding(start_t *list)
{
	if (ABS(list->end[1]) - ABS(list->start[1]) > 15
	|| ABS(list->end[0]) - ABS(list->start[0]) > 15)
		return (1);
	else if (ABS(list->end[1]) - ABS(list->start[1]) < -15
	|| ABS(list->end[0]) - ABS(list->start[0]) < -15)
		return (1);
	return (0);
}

void	get_end(int *pos, node_t **grid, obj_t *monster, map_t *map)
{
	int data[2];
	while (grid[pos[1]][pos[0]].state != 2) {
		if (grid[pos[1]][pos[0]].state == 3) {
			monster->pos_tile.x = (grid[pos[1]][pos[0]].father[0]
			* SCALE_MAP) + map->tr.x;
			monster->pos_tile.y = grid[pos[1]][pos[0]].father[1]
			* SCALE_MAP + map->tr.y;
		} else
			grid[pos[1]][pos[0]].state = 1;
		data[0] = grid[pos[1]][pos[0]].father[0];
		data[1] = grid[pos[1]][pos[0]].father[1];
		pos[0] = data[0];
		pos[1] = data[1];
	}
}

int	path_finding(map_t *map, win_t *win, obj_t *monster,
	monster_t *list_m)
{
	node_t **grid = malloc(sizeof(node_t *) * (map->height));
	fill(grid, map->colisions[0], map, list_m);
	int pos[2];
	start_t *list = inits_list(win, map, monster);
	init_path(pos, list, grid);
	if (block_path_finding(list) == 1)
		return (1);
	while (list->open_list->next != NULL) {
		find_min(list->open_list, grid, pos);
		add_closelist(list, pos[0], pos[1]);
		remove_openlist(list, pos);
		if (pos[0] == list->end[0] && pos[1] == list->end[1]) {
			get_end(pos, grid, monster, map);
			break;
		}
		fill_info(list, grid, pos, map);
	}
	free_grid(list, grid, map);
	return (0);
}
