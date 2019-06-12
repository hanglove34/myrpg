/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	more_quest_dialogue(npc_t *new, char *s, int i)
{
	switch (s[i]) {
		case ('e'):
			while (new->tree && new->tree->prev)
				new->tree = new->tree->prev;
			new_quest_node(&(new->tree));
			new->tree->type = 3;
			new->tree->quest_nb = get_quest_nb(s, i);
			break;
	}
}

void	quest_dialogue(npc_t *new, char *s, int i)
{
	switch (s[i]) {
		case ('Q'):
			while (new->tree && new->tree->prev)
				new->tree = new->tree->prev;
			new_quest_node(&(new->tree));
			new->tree->quest_nb = get_quest_nb(s, i);
			break;
		case ('q'):
			while (new->tree && new->tree->prev)
				new->tree = new->tree->prev;
			new_quest_node(&(new->tree));
			new->tree->type = 2;
			new->tree->quest_nb = get_quest_nb(s, i);
			break;
		default:
			more_quest_dialogue(new, s, i);
			break;
	}
}

void	create_new_dialogue(npc_t *new, char *s, int i)
{
	switch (s[i]) {
		case ('A'):
			new_already_node(&(new->tree));
			break;
		case (34):
			new_left_node(&(new->tree));
			break;
		case ('1'):
			new_left_node(&(new->tree));
			if (new->tree->prev && new->tree->prev->type == 1) {
				new->tree->type = 4;
				new->tree->quest_nb = new->tree->prev->quest_nb;
			}
			break;
		default:
			quest_dialogue(new, s, i);
			break;
	}
}

void	new_already_node(tree_t **root)
{
	tree_t *new = malloc(sizeof(*new));

	new->main = NULL;
	new->leftstr = NULL;
	new->rightstr = NULL;
	new->midstr = NULL;
	new->mid = NULL;
	new->already = NULL;
	new->left = NULL;
	new->right = NULL;
	new->prev = NULL;
	new->type = 0;
	new->offset = 0;
	new->quest = NULL;
	new->quest_nb = 0;
	new->prev = *root;
	if (*root != NULL)
		new->prev->already = new;
	*root = new;
}

void	new_quest_node(tree_t **root)
{
	tree_t *new = malloc(sizeof(*new));
	tree_t *tmp = *root;

	*new = (tree_t){1, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL};
	new->prev = *root;
	while (tmp && tmp->quest)
		tmp = tmp->quest;
	if (tmp) {
		new->prev = tmp;
		tmp->quest = new;
	}
	*root = new;
}
