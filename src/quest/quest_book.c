/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int	display_book_status(win_t *win, int page, sfVector2i ind)
{
	quest_t *tmp = find_quest(win->quest, page);
	sfColor green = sfColor_fromRGBA(31, 122, 22, 255);
	if (tmp->state == 0) {
		sfRenderWindow_drawText(win->win,
		win->quest_book.status_txt[ind.y], NULL);
		return (1);
	} else if (tmp->state == 1) {
		sfText_setColor(win->quest_book.status_txt[ind.x], sfBlack);
		sfText_setString(win->quest_book.status_txt[ind.x],
		"Status : In Progress");
		sfRenderWindow_drawText(win->win,
		win->quest_book.status_txt[ind.x], NULL);
	} else if (tmp->state == 3) {
		sfText_setColor(win->quest_book.status_txt[ind.x], green);
		sfText_setString(win->quest_book.status_txt[ind.x],
		"Status : Completed");
		sfRenderWindow_drawText(win->win,
		win->quest_book.status_txt[ind.x], NULL);
	}
	return (0);
}

void	display_book_rewards(win_t *win, int nb)
{
	int i = 0;

	while (i < win->quest_book.nb_rewards[nb]) {
		sfRenderWindow_drawSprite(win->win,
		win->quest_book.rewards[nb][i], NULL);
		i += 1;
	}
}

void	display_quest_book(win_t *win)
{
	quest_t *tmp = win->quest;
	int nb = win->quest_book.page;
	quest_book_t book = win->quest_book;
	sfRenderWindow_drawText(win->win, book.page_nb[nb * 2 - 2], NULL);
	if (nb * 2 <= book.max_page)
		sfRenderWindow_drawText(win->win, book.page_nb[nb * 2 - 1],
		NULL);
	if (display_book_status(win, nb * 2 - 1, (sfVector2i){0, 2}) == 0) {
		sfRenderWindow_drawText(win->win,
		book.quest_txt[nb * 2 - 2], NULL);
		sfRenderWindow_drawText(win->win, book.reward_txt[0], NULL);
		display_book_rewards(win, nb * 2 - 2);
	}
	if (nb * 2 <= book.max_page &&
	display_book_status(win, nb * 2, (sfVector2i){1, 3}) == 0) {
		sfRenderWindow_drawText(win->win, book.quest_txt[nb * 2 - 1],
		NULL);
		sfRenderWindow_drawText(win->win, book.reward_txt[1], NULL);
		display_book_rewards(win, nb * 2 - 1);
	}
}

void	quest_book(win_t *win)
{
	if (win->quest_book.state[0] == -1) {
		return;
	}
	sfColor col1 = sfColor_fromRGBA(0, 0, 0, 0);
	sfColor col2 = sfColor_fromRGBA(0, 0, 0, 75);
	sfRenderWindow_drawSprite(win->win, win->quest_book.spr, NULL);
	display_quest_book(win);
	sfRectangleShape_setFillColor(win->quest_book.rect[0],
	(win->quest_book.state[1] == 1) ? col1 : col2);
	sfRectangleShape_setFillColor(win->quest_book.rect[1],
	(win->quest_book.state[2] == 1) ? col1 : col2);
	sfRenderWindow_drawRectangleShape(win->win, win->quest_book.rect[0],
	NULL);
	sfRenderWindow_drawRectangleShape(win->win, win->quest_book.rect[1],
	NULL);
}
