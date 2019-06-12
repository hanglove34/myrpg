/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	hitbox_spell_damage(win_t *win, monster_t *tmp,  obj_t *spell)
{
	if (spell->state[0] == -1)
		return;
	if (tmp->monster->pos.x > spell->pos.x - 50 &&
	tmp->monster->pos.x - 40 < spell->pos.x + 50) {
		if (tmp->monster->pos.y > spell->pos.y - 50 &&
		tmp->monster->pos.y - 40 < spell->pos.y + 50) {
			tmp->monster->stat.hp -= (1)
			/ (1 + (tmp->monster->stat.armor /500));
			change_damage(tmp, win, (1)
			/ (1+(tmp->monster->stat.armor /500)));
			change_print_bar(tmp, win);
			add_xp(win, tmp);
		}
	}
}

void	check_spell_damage(win_t *win, monster_t *monster,  obj_t *spell)
{
	monster_t *tmp = monster;
	while (tmp->next) {
		if (tmp->monster->stat.hp > 0) {
			hitbox_spell_damage(win, tmp, spell);
		}
		tmp = tmp->next;
	}
}

void	free_grid(start_t *list, node_t **grid, map_t *map)
{
	free_path(list->open_list);
	free_path(list->closed_list);
	free(list);
	for (int i = 0; i < map->height; i++)
		free(grid[i]);
	free(grid);
}

void	fill_posm(monster_t *list_m, node_t **grid, map_t *map)
{
	int x = 0;
	int m = 0;
	for (monster_t *tmp = list_m; tmp->next; tmp = tmp->next) {
		m = (tmp->monster->pos.y - map->tr.y) / SCALE_MAP;
		x = (tmp->monster->pos.x - map->tr.x) / SCALE_MAP;
		grid[m][x].state = -1;
	}
}
