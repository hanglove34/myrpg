/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

int	number_of_tileset(char *filename)
{
	int fd = open(filename, O_RDONLY);
	char *buff = get_next_line(fd);
	int i = 0;

	while (my_strncmp(buff, "[tilesets]", my_strlen("[tilesets]")) != 0) {
		free(buff);
		buff = get_next_line(fd);
	}
	buff = get_next_line(fd);
	while (my_strncmp(buff, "tileset=", my_strlen("tileset=")) == 0 ) {
		i++;
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	close(fd);
	return (i);
}

void	fill_tilesets(char **tilesets, int fd)
{
	char **arg = NULL;
	char *buff = get_next_line(fd);
	int i = 0;

	while (my_strncmp(buff, "[tilesets]", my_strlen("[tilesets]")) != 0) {
		buff = get_next_line(fd);
	}
	buff = get_next_line(fd);
	arg = my_str_to_word_array(buff, '=');
	while (my_strncmp(buff, "tileset=", my_strlen("tileset=")) == 0 ) {
		tilesets[i++] = my_strdup(arg[1]);
		buff = get_next_line(fd);
		arg = my_str_to_word_array(buff, '=');
	}
	free(buff);
}

void	get_value(char *name, int  *value, char *filename)
{
	int fd = open(filename, O_RDONLY);
	char **arg = NULL;
	char *buff = get_next_line(fd);

	while (my_strncmp(buff, name, my_strlen(name)) != 0) {
		free(buff);
		buff = get_next_line(fd);
	}
	arg = my_str_to_word_array(buff, '=');
	*value = my_getnbr(arg[1]);
	free(buff);
}

char	**get_tilesets(char *filename, int *w, int *h, map_t *map)
{
	char *buff = NULL;
	char **tilesets = NULL;
	int fd = 0;

	map->nb_tileset = number_of_tileset(filename);
	tilesets = malloc(sizeof(*tilesets) * (map->nb_tileset + 1));
	fd = open(filename, O_RDONLY);
	buff = get_next_line(fd);
	tilesets[map->nb_tileset] = NULL;
	fill_tilesets(tilesets, fd);
	close(fd);
	get_value("width=", w, filename);
	get_value("height=", h, filename);
	return (tilesets);
}
