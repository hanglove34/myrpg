/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

int	test_index_used(ll_t *list, int n)
{
	ll_t *tmp = list;

	while (tmp != NULL) {
		if (tmp->index == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	get_textures(info_tex_t info, ll_t *list, sfTexture **tex)
{
	int w = info.info.x;
	sfTexture *texture = NULL;
	int i = 0;
	int j = 0;
	sfIntRect rec = {0, 0, 16, 16};

	while (i < info.info.y) {
		rec = (sfIntRect){16 * j, 16 * i, 16, 16};
		if (test_index_used(list, *info.n + 1))
			texture = sfTexture_createFromFile(info.filename, &rec);
		else
			texture = NULL;
		tex[info.rmd + (i * w + j)] = texture;
		(*info.n)++;
		j++;
		if (j == w) {
			i++;
			j = 0;
		}
	}
}

int	add_textures_in_tex(sfTexture **tex, sfVector2i info,
	char *filename, ll_t *list)
{
	static int n = 0;
	sfTexture *texture = NULL;
	int i = 0;
	int j = 0;
	sfIntRect area = {0, 0, 16, 16};
	int rmd = 0;
	int w = info.x;
	int h = info.y;

	if (filename == NULL) {
		n = 0;
		return (0);
	}
	rmd = n;
	get_textures((info_tex_t){info, filename, rmd, &n}, list, tex);
	return (n);
}

int	get_max_index(tilesets_t tileset[14], char **tilesets_name)
{
	int i = 0;
	int j = 0;
	int n = 0;
	int w = 0;
	int h = 0;

	while (tilesets_name[i] != NULL) {
		while (my_strcmp(tilesets_name[i], tileset[j].filename) != 0) {
			j++;
		}
		w = tileset[j].w;
		h = tileset[j].h;
		n += w * h;
		j = 0;
		i++;
	}
	return (n);
}

sfTexture **get_tex(char **tilesets_name, tilesets_t tileset[],
	ll_t *list, map_t *map)
{
	sfTexture *texture = NULL;
	int n = 0;
	int i = 0;
	int j = 0;
	int w = 0;
	int h = 0;

	map->nb_tex = get_max_index(tileset, tilesets_name);
	sfTexture **tex = malloc(sizeof(*tex) * map->nb_tex);
	while (n != map->nb_tex) {
		while (my_strcmp(tilesets_name[j], tileset[i].filename) != 0)
			i++;
		w = tileset[i].w;
		h = tileset[i].h;
		n = add_textures_in_tex(tex, (sfVector2i){w, h},
		tileset[i].filename, list);
		j++;
		i = 0;
	}
	return (tex);
}
