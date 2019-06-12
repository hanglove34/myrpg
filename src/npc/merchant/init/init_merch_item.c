/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	new_merch_sprites(merch_item_t *new, win_t *win, int nb,
	sfVector2f pos)
{
	new->square = sfSprite_create();
	new->item = sfSprite_create();
	new->pos = pos;
	sfSprite_setTexture(new->item, win->item[nb].img, sfTrue);
	sfSprite_setTexture(new->square, win->invent[1].img, sfTrue);
	sfSprite_setTextureRect(new->item, win->item[nb].rect);
	sfSprite_setPosition(new->item, (sfVector2f){pos.x + 13, pos.y + 13});
	sfSprite_setPosition(new->square, pos);
	sfSprite_setScale(new->square, (sfVector2f){1.5, 1.5});
	sfSprite_setScale(new->item, (sfVector2f){1.5, 1.5});
}

void	new_merch_stat_str(merch_item_t *new, win_t *win, int nb)
{
	new->stat_str = malloc(sizeof(char *) * 7);

	new->stat_str[0] = my_getstr(win->item[nb].stat.hp);
	new->stat_str[1] = my_getstr(win->item[nb].stat.armor);
	new->stat_str[2] = my_getstr(win->item[nb].stat.atk);
	new->stat_str[3] = my_getstr(win->item[nb].stat.crit);
	new->stat_str[4] = my_getstr(win->item[nb].stat.spd);
	new->stat_str[5] = my_getstr(win->item[nb].stat.mana);
	new->stat_str[6] = my_getstr(win->item[nb].stat.gold);
}

void	new_item_merch(merch_item_t **root, int item, win_t *win,
	sfVector2f pos)
{
	merch_item_t *tmp = *root;
	merch_item_t *new = malloc(sizeof(*new));

	new->state[0] = 0;
	new->state[1] = 0;
	new->state[2] = 0;
	new->nb = item;
	new_merch_stat_str(new, win, item);
	new_merch_sprites(new, win, item, pos);
	new->prev = NULL;
	new->next = NULL;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp == NULL)
		*root = new;
	else {
		new->prev = tmp;
		tmp->next = new;
	}
}

void	init_merch_items(npc_t *new, win_t *win, char **tab)
{
	int nb = my_getnbr(tab[7]);
	int i = 0;
	new->merch.items = NULL;
	sfVector2f pos = {0, 500};

	while (i != nb) {
		pos.x = 80 + (102 * (i / 2));
		pos.y = (i % 2 == 0) ? 390 : 510;
		new_item_merch(&(new->merch.items),
		my_getnbr(tab[8 + i]), win, pos);
		i += 1;
	}
}
