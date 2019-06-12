/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	free_quest_node(tree_t **node)
{
	tree_t *tmp = *node;

	(*node)->prev->quest = (*node)->quest;
	if ((*node)->quest)
		(*node)->quest->prev = (*node)->prev;
	*node = (*node)->prev;
	free(tmp->main);
	if (tmp->left) {
		free(tmp->leftstr);
		free(tmp->left->main);
		free(tmp->left);
	}
	if (tmp->mid) {
		free(tmp->midstr);
		free(tmp->mid->main);
		free(tmp->mid);
	}
	free(tmp);
}

void	remove_all_quest_node_in_scene(scene_t *scene, int nb)
{
	int i = 0;

	while (i != NB_SCENE) {
		if (scene[i].init != 0)
			remove_all_quest_node(scene[i].npc, nb);
		i += 1;
	}
}

void	remove_all_quest_node(npc_t *tmp, int nb)
{
	npc_t *npc = tmp;

	while (npc && npc->prev)
		npc = npc->prev;
	while (npc) {
		if (npc->tree->quest_nb == nb)
			free_quest_node(&npc->tree);
		npc = npc->next;
	}
}
