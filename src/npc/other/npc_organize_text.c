/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

char	*cut_word(char *str, int i)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 3));
	int j = 0;

	while (j != i) {
		new[j] = str[j];
		j += 1;
	}
	new[j] = '-';
	new[j + 1] = '\n';
	j += 2;
	while (str[i]) {
		new[j] = str[i];
		j += 1;
		i += 1;
	}
	new[j] = '\0';
	return (new);
}

void	cut_text(npc_t *npc)
{
	int i = 0;
	sfVector2f pos;

	while (npc->tree->main[i]) {
		sfText_setString(npc->text[0], npc->tree->main);
		pos = sfText_findCharacterPos(npc->text[0], i);
		if (npc->tree->main[i] == ' ' && pos.x >= WIDTH - 150)
			npc->tree->main[i] = '\n';
		else if (npc->tree->main[i] != '-' &&
		npc->tree->main[i] != '\n' && npc->tree->main[i + 1] != ' ' &&
		pos.x >= WIDTH - 70)
			npc->tree->main = cut_word(npc->tree->main, i);
		i += 1;
	}
}

void	scroll_one_line(npc_t *npc)
{
	int j = 0;

	while (npc->tree->main[j] && npc->tree->main[j] != '\n')
		j += 1;
	j += 1;
	npc->tree->main += j;
	npc->txt_i -= j;
	npc->tree->offset += j;
}

void	scroll_text(int i, sfText *text, npc_t *npc)
{
	sfVector2f pos;

	if (i == 0)
		return;
	pos = sfText_findCharacterPos(text, i - 1);
	if (npc->tree->main[i] == '\n' && pos.y >= DIALOG_BOX_POSY + (3 * 46))
		scroll_one_line(npc);
	else if (!npc->tree->main[npc->txt_i] && pos.y >= DIALOG_BOX_POSY +
	(3 * 46) && npc->tree->leftstr)
		scroll_one_line(npc);
}
