/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	valid_answer(npc_t *npc, win_t *win)
{
	npc_t *tmp = find_active_npc(npc);

	if (tmp == NULL || tmp->cursor.state == 0 || tmp->state[0] == 1 ||
	tmp->state[3] != 0)
		return;
	switch (tmp->cursor.answer) {
		case (1):
			if (tmp->type == SAVE)
				win->ver[2] = 1;
			tmp->tree = tmp->tree->left;
			break;
		case (2):
			tmp->tree = tmp->tree->mid;
			break;
		case (3):
			tmp->tree = tmp->tree->right;
			break;
	}
	tmp->txt_i = 0;
	tmp->cursor.state = 0;
}

npc_t	*find_active_npc(npc_t *npc)
{
	npc_t *tmp = npc;
	npc_t *result;

	while (npc != NULL) {
		if (npc->active == 1) {
			result = npc;
			npc = tmp;
			return (result);
		}
		npc = npc->next;
	}
	npc = tmp;
	return (NULL);
}

void	blink_cursor(ans_curs_t cursor)
{
	static int dir = -1;
	static int alpha = 255;
	sfColor color;

	cursor.blink.time = sfClock_getElapsedTime(cursor.blink.clock);
	cursor.blink.sec = cursor.blink.time.microseconds / 1000000.0;
	if (cursor.blink.sec >= 0.05) {
		alpha += (dir * 17);
		if (alpha <= 0 || alpha >= 255)
			dir = -dir;
		color = sfColor_fromRGBA(255, 255, 255, alpha);
		sfSprite_setColor(cursor.spr, color);
		sfClock_restart(cursor.blink.clock);
	}
}

void	move_cursor_left(npc_t *npc)
{
	npc_t *tmp = find_active_npc(npc);
	int i;

	if (tmp == NULL || tmp->cursor.state == 0 || tmp->state[3] != 0)
		return;
	if (tmp->cursor.answer > 1) {
		tmp->cursor.answer -= 1;
		sfSprite_setPosition(tmp->cursor.spr,
		tmp->cursor.pos[tmp->cursor.answer - 1]);
	}
}

void	move_cursor_right(npc_t *npc)
{
	npc_t *tmp = find_active_npc(npc);
	int i;
	int nb_ans = 3;

	if (tmp == NULL || tmp->cursor.state == 0 || tmp->state[3] != 0)
		return;
	if (tmp->tree->right == NULL)
		nb_ans = 2;
	if (tmp->cursor.answer < nb_ans) {
		tmp->cursor.answer += 1;
		sfSprite_setPosition(tmp->cursor.spr,
		tmp->cursor.pos[tmp->cursor.answer - 1]);
	}
}
