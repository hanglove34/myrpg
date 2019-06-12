/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	switch_new_node(npc_t *new, char *s, int i)
{
	switch (s[i]) {
		case ('2'):
			new->tree = new->tree->prev;
			new_mid_node(&(new->tree));
			if (new->tree->prev && new->tree->prev->type == 1) {
				new->tree->type = 5;
				new->tree->quest_nb = new->tree->prev->quest_nb;
			}
			break;
		case ('3'):
			new->tree = new->tree->prev;
			new_right_node(&(new->tree));
			break;
		default:
			create_new_dialogue(new, s, i);
			break;
	}
}
