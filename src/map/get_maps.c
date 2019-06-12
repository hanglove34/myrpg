/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

char	*fill_index_map_static(int *map, int *count, sfVector2f info,
	ll_t **list)
{
	char **arr = NULL;
	int i = 0;
	char *s = NULL;
	int fd = info.x;
	int w = info.y;
	char del = 44;

	s = get_next_line(fd);
	if (s != NULL && s[0] != '\0') {
		arr = my_str_to_word_array_static(s, del);
		while (i < w) {
			map[*count] = my_getnbr(arr[i]);
			add_index_used(list, map[*count]);
			i++;
			(*count)++;
		}
	}
	return (s);
}

int	*give_map(int fd, map_t *map, ll_t **list)
{
	char *s = malloc(1);
	int *sol = NULL;
	char **arr = NULL;
	int *new = NULL;
	int cnt = 0;
	int h = map->height - 1;
	int w = map->weidth - 1;

	s[0] = 'a';
	new = malloc(sizeof(*new) * w * h);
	while (s != NULL) {
		if (s[0] == '\0')
			break;
		free(s);
		s = fill_index_map_static(new, &cnt, (sfVector2f){fd, w}, list);
	}
	if (s)
		free(s);
	return (new);
}

int	number_of_sol(char *filename, char *name)
{
	int fd = open(filename, O_RDONLY);
	int i = 0;
	char *buff = NULL;

	buff = get_next_line(fd);
	while (buff != NULL) {
		if (my_strncmp(buff, name, my_strlen(name)) == 0)
			i++;
		free(buff);
		buff = get_next_line(fd);
	}
	close(fd);
	free(buff);
	return (i);
}

char	*go_to_map(char *buff, char *name, int fd)
{
	while (my_strncmp(buff, name, my_strlen(name)) != 0) {
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	buff = get_next_line(fd);
	return (buff);
}

int	**get_maps(char *filename, map_t *map, char *name, ll_t **list)
{
	char *buff = NULL;
	int **sols = NULL;
	int fd = 0;
	int i = 0;
	int n = number_of_sol(filename, name);

	sols = malloc(sizeof(*sols) * n);
	fd = open(filename, O_RDONLY);
	buff = get_next_line(fd);
	while (i < n) {
		buff = go_to_map(buff, name, fd);
		free(buff);
		sols[i] = give_map(fd, map, list);
		i++;
		buff = get_next_line(fd);
	}
	free(buff);
	close(fd);
	return (sols);
}
