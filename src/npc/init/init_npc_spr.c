/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

sfIntRect	get_npc_rect(char **tab)
{
	sfIntRect rect = {0, 0, 78, 108};
	int left = 0;
	int top = 0;

	left = my_getnbr(tab[2]);
	top = my_getnbr(tab[3]);
	rect.left = left * 78;
	rect.top = top * 108;
	return (rect);
}

sfVector2f	get_npc_pos(char **tab)
{
	sfVector2f pos = {0, 0};

	pos.x = my_getnbr(tab[4]);
	pos.y = my_getnbr(tab[5]);
	pos.x = pos.x * 40 + 22;
	pos.y = pos.y * 40 + 22;
	return (pos);
}

void	init_npc_rect(npc_t *new, char **tab)
{
	char *s;

	new->state[0] = -1;
	new->state[1] = -1;
	new->state[2] = 1;
	new->state[3] = 0;
	new->tex = sfTexture_createFromFile(tab[1], NULL);
	new->rect[0] = get_npc_rect(tab);
	new->rect[1] = (sfIntRect){new->rect[0].left,
	new->rect[0].top + 108, 78, 108};
	new->rect[2] = (sfIntRect){new->rect[1].left,
	new->rect[1].top + 108, 78, 108};
	new->rect[3] = (sfIntRect){new->rect[2].left,
	new->rect[2].top + 108, 78, 108};
}

void	init_dial_spr(npc_t *new, win_t *win)
{
	new->dial_spr = sfSprite_create();
	sfSprite_setTexture(new->dial_spr, new->tex, sfTrue);
	sfSprite_setTextureRect(new->dial_spr, new->rect[0]);
	sfSprite_setOrigin(new->dial_spr, (sfVector2f){39, 54});
	sfSprite_setScale(new->dial_spr, (sfVector2f){5, 5});
	sfSprite_setPosition(new->dial_spr, (sfVector2f){200, 450});
	new->pict = sfSprite_create();
	sfSprite_setTexture(new->pict, win->item[1].img, sfTrue);
	sfSprite_setOrigin(new->pict, (sfVector2f){16, 16});
	sfSprite_setScale(new->pict, (sfVector2f){1.75, 1.75});
	new->clocks[0].clock = sfClock_create();
	new->clocks[2].clock = sfClock_create();
	new->pict_move[0] = 0;
	new->pict_move[1] = 1;
}

void	new_npc_spr(npc_t *new, char **tab, win_t *win)
{
	new->type = NORM;
	init_npc_rect(new, tab);
	init_dial_spr(new, win);
	new->spr = sfSprite_create();
	new->pos = get_npc_pos(tab);
	sfSprite_setTexture(new->spr, new->tex, sfTrue);
	sfSprite_setTextureRect(new->spr, new->rect[0]);
	sfSprite_setOrigin(new->spr, (sfVector2f){39, 108});
	sfSprite_setPosition(new->spr, new->pos);
	if (tab[6][0] == '1')
		new_npc_merchant(new, win, tab);
	else if (tab[6][0] == '2')
		new_save_point(new, win, tab);
}
