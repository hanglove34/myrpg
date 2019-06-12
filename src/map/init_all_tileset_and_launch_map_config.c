/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	destroy_config(ll_t *list, char **tilesets_name, map_t *map)
{
	int i = 0;

	free(list);
	while (i < map->nb_tileset) {
		free(tilesets_name[i]);
		i++;
	}
}

void	fill_maps(map_t *map, char *filename, ll_t **list, win_t *win)
{
	map->sols = get_maps(filename, map, "type=sol", list);
	print_loading_screen(win, 2);
	map->decores = get_maps(filename, map, "type=decor", list);
	print_loading_screen(win, 3);
	map->colisions = get_maps(filename, map, "type=collision", list);
	print_loading_screen(win, 4);
	map->map_event = get_maps(filename, map, "type=event", list);
	print_loading_screen(win, 5);
	map->nb_map_event = number_of_sol(filename, "type=event");
	print_loading_screen(win, 6);
	map->nb_sols = number_of_sol(filename, "type=sol");
	print_loading_screen(win, 7);
	map->nb_decores = number_of_sol(filename, "type=decor");
	print_loading_screen(win, 8);
	map->nb_colisions = number_of_sol(filename, "type=collision");
	print_loading_screen(win, 9);
}

int	fill_map_from_config_fill(char *filename, map_t *map,
	tilesets_t tilesets[], win_t *win)
{
	char **tilesets_name = NULL;
	int w = 0;
	int h = 0;
	ll_t *list = malloc(sizeof(*list));

	list->index = 0;
	list->next = NULL;
	add_textures_in_tex(NULL, (sfVector2i){0, 0}, NULL, NULL);
	print_loading_screen(win, 1);
	tilesets_name = get_tilesets(filename, &w, &h, map);
	map->weidth = w + 1;
	map->height = h + 1;
	fill_maps(map, filename, &list, win);
	map->tex = get_tex(tilesets_name, tilesets, list, map);
	map->size = w * h;
	map->event = -42;
	destroy_config(list, tilesets_name, map);
	return (0);
}

int	init_rest_tileset(tilesets_t tileset[14], map_t *map,
	char *filename, win_t *win)
{
	tilesets_t ff_master = {"tileset/ff_master_tile_sheet.png", 41, 52};
	tilesets_t house = {"tileset/house.png", 69, 38};
	tilesets_t doors = {"tileset/doors.png", 12, 16};
	tilesets_t tileA1_town = {"tileset/tileA1_town.png", 16, 12};
	tilesets_t castle = {"tileset/castle.png", 34, 17};
	tilesets_t inside = {"tileset/inside.png", 48, 35};
	tilesets_t winter = {"tileset/tf_winter_water.png", 22, 31};
	tilesets_t terrain = {"tileset/terrain.png", 39, 38};

	tileset[7] = (tilesets_t)ff_master;
	tileset[8] = (tilesets_t)house;
	tileset[9] = (tilesets_t)doors;
	tileset[10] = (tilesets_t)tileA1_town;
	tileset[11] = (tilesets_t)castle;
	tileset[12] = (tilesets_t)inside;
	tileset[13] = (tilesets_t)winter;
	tileset[14] = (tilesets_t)terrain;
	fill_map_from_config_fill(filename, map, tileset, win);
	return (0);
}

int	init_all_tileset_and_launch_map_config(map_t *map,
	char *filename, win_t *win)
{
	tilesets_t jungle = {"tileset/tf_jungle_tileset.png", 22, 21};
	tilesets_t outside = {"tileset/outside.png", 52, 24};
	tilesets_t colision = {"tileset/collision.png", 1, 1};
	tilesets_t cave = {"tileset/cave_tileset.png", 8, 16};
	tilesets_t cave2 = {"tileset/cave2_tileset.png", 16, 16};
	tilesets_t water = {"tileset/water.png", 51, 55};
	tilesets_t dungeon = {"tileset/dungeon.png", 51, 29};
	tilesets_t tileset[15];

	tileset[0] = (tilesets_t)jungle;
	tileset[1] = (tilesets_t)outside;
	tileset[2] = (tilesets_t)colision;
	tileset[3] = (tilesets_t)cave;
	tileset[4] = (tilesets_t)cave2;
	tileset[5] = (tilesets_t)water;
	tileset[6] = (tilesets_t)dungeon;
	init_rest_tileset(tileset, map, filename, win);
	return (0);
}
