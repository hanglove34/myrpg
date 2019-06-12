/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	decrease_red_color(sfColor *color,
	int offset, sfBool alpha, int offset_alpha)
{
	if (alpha && color->a + offset_alpha <= 0xff)
		color->a += offset_alpha;
	if (color->r + offset <= 0xff)
		color->r += offset;
	if (color->g + offset <= 0xff)
		color->g += offset;
	if (color->b + offset <= 0xff)
		color->b += offset;
}
