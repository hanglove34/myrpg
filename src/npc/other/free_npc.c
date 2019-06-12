/*
** EPITECH PROJECT, 2018
** free npc
** File description:
** my_rpg
*/

#include "my.h"

void	free_all_npc(npc_t *npc)
{
	npc_t *tmp = npc;

	while (npc) {
		tmp = npc;
		npc = npc->next;
		free_npc(tmp);
	}
}

void	free_tab(char **tab)
{
	int i = 0;

	while (tab[i])
		i += 1;
	i -= 1;
	while (i >= 0) {
		free(tab[i]);
		i -= 1;
	}
}

void	free_merch_items(merch_item_t *merch)
{
	merch_item_t *tmp = merch;

	while (merch) {
		tmp = merch;
		merch = merch->next;
		sfSprite_destroy(tmp->square);
		sfSprite_destroy(tmp->item);
		free_tab(tmp->stat_str);
	}
}

void	free_merch(merch_t merch)
{
	sfRectangleShape_destroy(merch.rect);
	sfTexture_destroy(merch.buy_tex);
	sfSprite_destroy(merch.sell);
	sfSprite_destroy(merch.mouse);
	sfSprite_destroy(merch.sell);
	sfSprite_destroy(merch.left_arrow);
	sfSprite_destroy(merch.right_arrow);
	sfSprite_destroy(merch.close);
	for (int i = 0; i != 8; i++) {
		sfText_destroy(merch.stat[i]);
		sfSprite_destroy(merch.pict[i]);
	}
	free(merch.sum_str);
	free(merch.sell_str);
}

void	free_npc(npc_t *npc)
{
	sfFont_destroy(npc->font);
	for (int i = 0; i != 4; i++)
		sfText_destroy(npc->text[i]);
	free(npc->text);
	sfTexture_destroy(npc->tex);
	sfSprite_destroy(npc->spr);
	sfSprite_destroy(npc->dial_spr);
	sfRectangleShape_destroy(npc->dial.rect);
	sfTexture_destroy(npc->cursor.tex);
	sfSprite_destroy(npc->cursor.spr);
	sfClock_destroy(npc->cursor.blink.clock);
	sfClock_destroy(npc->clocks[0].clock);
	sfClock_destroy(npc->clocks[1].clock);
	if (npc->type == MERCH)
		free_merch(npc->merch);
	free(npc);
}
