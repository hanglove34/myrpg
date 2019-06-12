/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	fill_info_diago2(start_t *list, node_t **grid, int *xy, map_t *map)
{
	if (xy[0] > list->start[0] - 15 && xy[1] < list->start[1] + 15
		&& xy[0] > 0 && xy[1] < map->height - 2 &&
		grid[xy[1] + 1][xy[0] - 1].state != -1 &&
		grid[xy[1] + 1][xy[0]].state != -1 &&
		grid[xy[1]][xy[0] - 1].state != -1 &&
		is_in_list(list->open_list, list->closed_list,
		xy[0] - 1, xy[1] + 1) == 0) {
		fill_case(grid, list, (sfVector2i){xy[0] - 1, xy[1] + 1}, xy);
		add_openlist(list, xy[0] - 1, xy[1] + 1);
	}
	if (xy[1] > list->start[1] - 15 && xy[0] < list->start[0] + 15 &&
		xy[1] > 0 && xy[0] < map->weidth - 2
		&& grid[xy[1] - 1][xy[0] + 1].state != -1 &&
		grid[xy[1]][xy[0] + 1].state != -1 &&
		grid[xy[1] - 1][xy[0]].state != -1 &&
		is_in_list(list->open_list, list->closed_list,
		xy[0] + 1, xy[1] - 1) == 0) {
		fill_case(grid, list, (sfVector2i){xy[0] + 1, xy[1] - 1}, xy);
		add_openlist(list, xy[0] + 1, xy[1] - 1);
	}
}

void	fill_info_diago(start_t *list, node_t **grid, int *xy, map_t *map)
{
	if (xy[0] < list->start[0] + 15 && xy[1] < list->start[1] + 15 &&
		xy[0] < map->weidth - 2 && xy[1] < map->height - 2 &&
		grid[xy[1] + 1][xy[0] + 1].state != -1 &&
		grid[xy[1] + 1][xy[0]].state != -1 &&
		grid[xy[1]][xy[0] + 1].state != -1 &&
		is_in_list(list->open_list, list->closed_list,
		xy[0] + 1, xy[1] + 1) == 0) {
		fill_case(grid, list, (sfVector2i){xy[0] + 1, xy[1] + 1}, xy);
		add_openlist(list, xy[0] + 1, xy[1] + 1);
	} if (xy[0] > list->start[0] - 15 && xy[1] > list->start[1] - 15 &&
		xy[1] > 0 && xy[0] > 0
		&& grid[xy[1] - 1][xy[0] - 1].state != -1 &&
		grid[xy[1] - 1][xy[0]].state != -1 &&
		grid[xy[1]][xy[0] - 1].state != -1 &&
		is_in_list(list->open_list, list->closed_list,
		xy[0] - 1, xy[1] - 1) == 0) {
		fill_case(grid, list, (sfVector2i){xy[0] - 1, xy[1] - 1}, xy);
		add_openlist(list, xy[0] - 1, xy[1] - 1);
	}
	fill_info_diago2(list, grid, xy, map);
}

void	fill_info2(start_t *list, node_t **grid, int *xy, map_t *map)
{
	if (xy[0] < list->start[0] + 15 &&  xy[0] < map->weidth - 2 &&
		grid[xy[1]][xy[0] + 1].state != -1 &&
		is_in_list(list->open_list, list->closed_list,
		xy[0] + 1, xy[1] + 0) == 0) {
		fill_case_down(grid, list, (sfVector2i){xy[0] + 1, xy[1]}, xy);
		add_openlist(list, xy[0] + 1, xy[1]);
	}
	if (xy[1] < list->start[1] + 15 && xy[1] < map->height - 2
		&& grid[xy[1] + 1][xy[0]].state != -1 &&
		is_in_list(list->open_list, list->closed_list,
		xy[0] + 0, xy[1] + 1) == 0) {
		fill_case_down(grid, list, (sfVector2i){xy[0], xy[1] + 1}, xy);
		add_openlist(list, xy[0], xy[1] + 1);
	}
	fill_info_diago(list, grid, xy, map);
}

void	fill_info(start_t *list, node_t **grid, int *xy, map_t *map)
{
	if (xy[0] > list->start[0] - 15 && xy[0] > 0 &&
		grid[xy[1]][xy[0] - 1].state != -1 &&
		is_in_list(list->open_list, list->closed_list,
		xy[0] - 1, xy[1] + 0) == 0) {
		fill_case_down(grid, list, (sfVector2i){xy[0] - 1, xy[1]}, xy);
		add_openlist(list, xy[0] - 1, xy[1]);
	}
	if (xy[1] > list->start[1] - 15 && xy[1] > 0
		&& grid[xy[1] - 1][xy[0]].state != -1
		&& is_in_list(list->open_list, list->closed_list,
		xy[0] + 0, xy[1] - 1) == 0) {
		fill_case_down(grid, list,(sfVector2i){ xy[0], xy[1] - 1}, xy);
		add_openlist(list, xy[0] - 0, xy[1] - 1);
	}
	fill_info2(list, grid, xy, map);
}

void	check_ia(win_t *win, monster_t *tmp, map_t *map, monster_t *monster)
{
	if ((POS_MX < POS_X - (SCALE_MAP * 1.1)
	|| POS_MX > POS_X + (SCALE_MAP * 1.1))
	|| (POS_MY < POS_Y - (SCALE_MAP * 1.5)
	|| POS_MY > POS_Y + (SCALE_MAP * 1.5))) {
		move_ia_x(tmp);
		move_ia_y(tmp);
		if (path_finding(map, win, tmp->monster, monster) == 0)
			anim_ia(tmp);
		sfRectangleShape_setPosition(tmp->hp.rect,
		(sfVector2f){tmp->monster->pos.x - 35, tmp->monster->pos.y -
		(tmp->monster->rect.height + 6)});
		sfRectangleShape_setPosition(tmp->hp2.rect,
		(sfVector2f){tmp->monster->pos.x - 35, tmp->monster->pos.y -
		(tmp->monster->rect.height + 6)});
	} else {
		anim_ia_attack(tmp);
		ia_attack(win, monster);
	}
}
