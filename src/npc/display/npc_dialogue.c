/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	npc_active(npc_t *npc, int ind, win_t *win)
{
	npc_t *tmp = npc;

	while (tmp != NULL) {
		if (ind == tmp->i) {
			rotate_npc(tmp, win);
			restart_npc(tmp);
			move_dial_ptr(tmp, win);
			reset_value(win);
		}
		tmp = tmp->next;
	}
}

void	display_prop(npc_t *npc, win_t *win)
{
	if (!npc->tree->main[npc->txt_i] && npc->tree->leftstr != NULL) {
		sfText_setString(npc->text[1], npc->tree->leftstr);
		sfText_setString(npc->text[2], npc->tree->midstr);
		npc->cursor.state = 1;
	} else {
		sfText_setString(npc->text[1], NULL);
		sfText_setString(npc->text[2], NULL);
	}
	if (!npc->tree->main[npc->txt_i] && npc->tree->rightstr != NULL)
		sfText_setString(npc->text[3], npc->tree->rightstr);
	else
		sfText_setString(npc->text[3], NULL);
}

void	draw_text(npc_t *npc, win_t *win)
{
	if (npc->state[3] != 0)
		return;
	sfRenderWindow_drawSprite(win->win, npc->dial_spr, NULL);
	sfRenderWindow_drawRectangleShape(win->win, npc->dial.rect, NULL);
	display_prop(npc, win);
	sfRenderWindow_drawText(win->win, npc->text[0], NULL);
	sfRenderWindow_drawText(win->win, npc->text[1], NULL);
	sfRenderWindow_drawText(win->win, npc->text[2], NULL);
	sfRenderWindow_drawText(win->win, npc->text[3], NULL);
	if (npc->cursor.state == 1) {
		npc->cursor.fptr(npc->cursor);
		sfRenderWindow_drawSprite(win->win, npc->cursor.spr, NULL);
	}
}

void	display_text(npc_t *npc, win_t *win)
{
	static char c;
	float speed = (npc->state[0] == -1) ? 0.05 : 0.0005;
	npc->clocks[0].time = sfClock_getElapsedTime(npc->clocks[0].clock);
	npc->clocks[0].sec = npc->clocks[0].time.microseconds / 1000000.0;

	if (npc->clocks[0].sec > speed) {
		scroll_text(npc->txt_i, npc->text[0], npc);
		c = npc->tree->main[npc->txt_i];
		npc->tree->main[npc->txt_i] = '\0';
		sfText_setString(npc->text[0], npc->tree->main);
		npc->tree->main[npc->txt_i] = c;
		if (npc->tree->main[npc->txt_i] != '\0')
			npc->txt_i += 1;
		sfClock_restart(npc->clocks[0].clock);
	}
	merchant(npc, win);
	draw_text(npc, win);
}

void	npc_speak(npc_t *npc, win_t *win)
{
	npc_t *tmp = npc;

	while (tmp != NULL) {
		if (tmp->active == 1) {
			display_text(tmp, win);
			tmp = tmp;
			break;
		}
		tmp = tmp->next;
	}
}
