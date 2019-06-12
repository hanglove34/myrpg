/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	create_new_node(npc_t *new, char *s)
{
	int i = 0;

	while (s[i] == '\t')
		i += 1;
	while (s[i] == '0') {
		new->tree = new->tree->prev;
		i += 1;
	}
	switch_new_node(new, s, i);
}

void	fill_bin_tree(npc_t *new, int fd)
{
	int i = 0;
	char *s = get_next_line(fd);

	while (s[0] != '>') {
		create_new_node(new, s);
		new->tree->main = get_single_str(s, &i, fd);
		cut_text(new);
		if (s[i] == '?')
			get_prop_str(new->tree, &i, s);
		i = 0;
		free(s);
		s = get_next_line(fd);
	}
	while (new->tree->prev != NULL)
		new->tree = new->tree->prev;
}

void	new_left_node(tree_t **root)
{
	tree_t *new = malloc(sizeof(*new));

	new->main = NULL;
	new->leftstr = NULL;
	new->rightstr = NULL;
	new->midstr = NULL;
	new->mid = NULL;
	new->left = NULL;
	new->already = NULL;
	new->right = NULL;
	new->prev = NULL;
	new->offset = 0;
	new->type = 0;
	new->quest = NULL;
	new->quest_nb = 0;
	new->prev = *root;
	if (*root != NULL)
		new->prev->left = new;
	*root = new;
}

void	new_mid_node(tree_t **root)
{
	tree_t *new = malloc(sizeof(*new));

	new->main = NULL;
	new->leftstr = NULL;
	new->rightstr = NULL;
	new->midstr = NULL;
	new->mid = NULL;
	new->left = NULL;
	new->right = NULL;
	new->already = NULL;
	new->prev = NULL;
	new->offset = 0;
	new->quest = NULL;
	new->type = 0;
	new->quest_nb = 0;
	new->prev = *root;
	if (*root != NULL)
		new->prev->mid = new;
	*root = new;
}

void	new_right_node(tree_t **root)
{
	tree_t *new = malloc(sizeof(*new));

	new->main = NULL;
	new->leftstr = NULL;
	new->rightstr = NULL;
	new->midstr = NULL;
	new->mid = NULL;
	new->left = NULL;
	new->already = NULL;
	new->right = NULL;
	new->quest = NULL;
	new->prev = NULL;
	new->offset = 0;
	new->type = 0;
	new->quest_nb = 0;
	new->prev = *root;
	if (*root != NULL)
		new->prev->right = new;
	*root = new;
}
