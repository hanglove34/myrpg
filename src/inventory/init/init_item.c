/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

int	parseur(obj_t *item, char *str, int nb)
{
	static int ver = 0;
	if (str[0] == '>' || str[0] == '<')
		return (0);
	if (ver == 0) {
		init_parseur_base(item, str, nb);
		ver = 1;
		return (0);
	} else if (ver == 1) {
		init_parseur_stat(item, str, nb);
		ver = 0;
		return (0);
	}
	return (0);
}

int	size_of_malloc(void)
{
	int fd = open("other/item", O_RDONLY);
	char *str;
	int c = 0;

	str = get_next_line(fd);
	while (str != NULL){
		if (str[0] == '>')
			c++;
		free(str);
		str = get_next_line(fd);
	}
	return (c);
}

void	init_item(win_t *win)
{
	int c = size_of_malloc();
	int fd = open("other/item", O_RDONLY);
	obj_t *item = malloc(sizeof(obj_t) * c);
	char *str;
	int nb = 0;

	str = get_next_line(fd);
	while (str != NULL){
		if (str[0] != '#')
			parseur(item, str, nb);
		if (str[0] == '<')
			nb++;
		free(str);
		str = get_next_line(fd);
	}
	init_char_stat_item(item, c);
	win->item = item;
}
