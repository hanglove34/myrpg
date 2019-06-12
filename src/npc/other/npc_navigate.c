/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	display_quest_dial(npc_t *tmp, win_t *win)
{
	quest_t *quest;

	quest = find_quest(win->quest, tmp->tree->quest_nb);
	if (tmp->tree->type == 0)
		tmp->state[1] = 1;
	else if (tmp->tree->type == 4 && quest && quest->state == 0) {
		quest->state = 1;
		tmp->tree = tmp->tree->prev;
		if (tmp->tree->offset != 0) {
			tmp->tree->main -= tmp->tree->offset;
			tmp->tree->offset = 0;
		}
		free_quest_node(&tmp->tree);
	} else if (tmp->tree->type == 3) {
		quest->state = 3;
		free_quest_node(&tmp->tree);
		remove_all_quest_node(tmp, 1);
	}
}

void	move_dial_ptr(npc_t *npc, win_t *win)
{
	quest_t *quest;
	tree_t *tmp = npc->tree;

	if (npc->tree->quest && tmp->quest->type == 2) {
		tmp = tmp->quest;
		quest = find_quest(win->quest, tmp->quest_nb);
		if (quest->state == 2 || quest->state == 3)
			free_quest_node(&tmp);
	}
	if (npc->tree->quest && npc->tree->quest->type == 1)
		npc->tree = npc->tree->quest;
	else if (npc->tree->quest && npc->tree->quest->type != 1) {
		quest = find_quest(win->quest, npc->tree->quest->quest_nb);
		if (npc->tree->quest->type == 2 && quest->state == 1)
			npc->tree = npc->tree->quest;
		else if (npc->tree->quest->type == 3 && (quest->state == 2
		|| quest->state == 1))
			npc->tree = npc->tree->quest;
	} else if (npc->state[1] == 1 && npc->tree->already)
		npc->tree = npc->tree->already;
}

void	go_to_next_sentence(npc_t *npc, win_t *win)
{
	npc_t *tmp = find_active_npc(npc);

	if (tmp == NULL || tmp->cursor.state == 1 || tmp->state[3] != 0 ||
	tmp->tree->main[tmp->txt_i] || tmp->state[0] == 1)
		return;
	tmp->txt_i = 0;
	if (tmp->tree->left != NULL)
		tmp->tree = tmp->tree->left;
	else {
		display_quest_dial(tmp, win);
		npc_active(npc, tmp->i, win);
		win->state = 0;
	}
}

npc_t	*find_npc(npc_t *npc, int ind)
{
	npc_t *tmp = npc;

	while (tmp) {
		if (tmp->i == ind)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
