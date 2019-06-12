/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	add_itm_list(int item, loot_t **root, win_t *win, sfVector2f
	pos)
{
	loot_t *new = malloc(sizeof(loot_t));
	loot_t *tmp = *root;
	new->item = item;
	new->del = 0;
	inits_t bourse = inits_pos_rect(&bourse, pos,
	(sfIntRect){0, 32, 32, 32}, (sfVector2f){1.5, 1.5});
	new->add = *create_object("img/item.png", bourse, 1, EMPTY);
	new->next = NULL;
	for (; tmp && tmp->next; tmp = tmp->next);
	if (tmp == NULL)
		*root = new;
	else
		tmp->next = new;
}

void	list_loot_item(purse_t *purse, int *item, win_t *win)
{
	int i = 0;
	int c = 0;
	sfVector2f pos = {235, 210};
	purse->loot = NULL;
	for (; item[i] != -1; i++);
	for (; c != i; c++, pos.y += 60) {
		add_itm_list(item[c], &purse->loot, win, pos);
	}
}

void	insertion_loot(win_t *win, int map, sfVector2f pos, int *item)
{
	purse_t *new = malloc(sizeof(*new));
	purse_t *tmp = win->purse;
	new->map = map;
	new->pos = pos;
	new->item = item;
	new->ver = 0;
	inits_t bourse = inits_pos_rect(&bourse, pos,
	(sfIntRect){416, 384, 32, 32}, (sfVector2f){1.5, 1.5});
	new->sprt = *create_object("img/item.png", bourse, 1, EMPTY);
	list_loot_item(new, item, win);
	sfSprite_setOrigin(new->sprt.spt, (sfVector2f){16, 16});
	new->next = NULL;
	for (; tmp && tmp->next; tmp = tmp->next);
	if (tmp == NULL)
		win->purse = new;
	else
		tmp->next = new;
}

void	move_bourse_on_map(purse_t *list, sfVector2f offset)
{
	purse_t *tmp = list;

	while (tmp) {
		tmp->pos.x += offset.x;
		tmp->pos.y += offset.y;
		sfSprite_setPosition(tmp->sprt.spt, tmp->pos);
		tmp = tmp->next;
	}
}
