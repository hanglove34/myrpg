/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg
*/

#include "my.h"

void	luminosity_less(win_t *win, scene_t *s)
{
	(void) s;
	if (win->luminosity < 150)
		win->luminosity += 30;
	sfRectangleShape_setFillColor(win->background[15].rect,
	sfColor_fromRGBA(0, 0, 0, win->luminosity));
}

void	luminosity_add(win_t *win, scene_t *s)
{
	(void) s;
	if (win->luminosity > 0)
		win->luminosity -= 30;
	sfRectangleShape_setFillColor(win->background[15].rect,
	sfColor_fromRGBA(0, 0, 0, win->luminosity));
}

void	go_to_next_line(int *state, char **str, int fd, char *str2)
{
	(*state)++;
	(*str) = my_strcat(*str, str2);
	(*str) = my_strcat(*str, "\n");
}
