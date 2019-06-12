/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	skip_quest_dialogues(quest_t *quest_tmp, npc_t *tmp)
{
	tree_t *tree_tmp;

	while (tmp) {
		if (quest_tmp->state == 1 && tmp->tree->quest &&
		tmp->tree->quest->quest_nb == quest_tmp->nb &&
		tmp->tree->quest->type == 1) {
			tree_tmp = tmp->tree->quest;
			free_quest_node(&tree_tmp);
		}
		if (quest_tmp->state > 1 && tmp->tree->quest &&
		tmp->tree->quest->quest_nb == quest_tmp->nb) {
			tree_tmp = tmp->tree->quest;
			free_quest_node(&tree_tmp);
			continue;
		}
		tmp = tmp->next;
	}
}

void	skip_dialogues(npc_t *npc, quest_t *quest)
{
	quest_t *quest_tmp = quest;
	npc_t *tmp = npc;

	while (tmp && tmp->tree && tmp->tree->prev)
		tmp->tree = tmp->tree->prev;
	while (quest_tmp) {
		skip_quest_dialogues(quest_tmp, tmp);
		quest_tmp = quest_tmp->next;
		tmp = npc;
	}
}
