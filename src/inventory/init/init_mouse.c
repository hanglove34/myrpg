/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	init_struct_mouse(mouse_t *mouse)
{
	mouse->ver = 0;
	mouse->pos.x = 0;
	mouse->pos.y = 0;
	mouse->item = 0;
	mouse->type = EMPTY;
	mouse->save.x = 0;
	mouse->save.y = 0;
	mouse->inv = 0;
}

void	init_liste_item(win_t *win)
{
	int *item = malloc(sizeof(int) * 4);
	item[0] = 1;
	item[1] = 2;
	item[2] = 1;
	item[3] = -1;
}
