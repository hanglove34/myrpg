/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	valid_quest_five(win_t *win, quest_t *quest, scene_t *scene)
{
	npc_t *tmp;

	if (win->state == -4) {
		quest->state = 3;
		win_give_item(win, 8);
		win_give_item(win, 9);
		win_give_item(win, 10);
		win_give_item(win, 11);
		win_give_item(win, 12);
		remove_all_quest_node_in_scene(scene, 4);
	}
}
