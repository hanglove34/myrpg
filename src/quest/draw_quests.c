/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	draw_quests(win_t *win)
{
	quest_t *tmp = win->quest;

	while (tmp) {
		if (tmp->state == 1 || tmp->state == 2) {
			move_quest_rect_right(tmp);
			sfText_setColor(tmp->text.txt, sfWhite);
			sfRenderWindow_drawRectangleShape(win->win,
			tmp->rect.rect, NULL);
			sfRenderWindow_drawText(win->win, tmp->text.txt, NULL);
		}
		else if (tmp->state == 3 && tmp->rect.pos.x != -300) {
			move_quest_rect_left(tmp);
			sfText_setColor(tmp->text.txt, sfGreen);
			sfRenderWindow_drawRectangleShape(win->win,
			tmp->rect.rect, NULL);
			sfRenderWindow_drawText(win->win, tmp->text.txt, NULL);
		}
		tmp = tmp->next;
	}
}
