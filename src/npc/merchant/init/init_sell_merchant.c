/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	init_sell_merchant(npc_t *new, win_t *win)
{
	sfIntRect rect = {4 * 32, 13 * 32, 32, 32};
	new->merch.sell = sfSprite_create();
	sfSprite_setTexture(new->merch.sell, win->pict[6].img, sfTrue);
	sfSprite_setTextureRect(new->merch.sell, rect);
	sfSprite_setOrigin(new->merch.sell, (sfVector2f){16, 16});
	sfSprite_setScale(new->merch.sell, (sfVector2f){1.5, 1.5});
	sfSprite_setPosition(new->merch.sell, (sfVector2f){76, 626});
	new->merch.sell_str = my_strdup("0");
	new->merch.state = 0;
}
