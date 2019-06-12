/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	init_book_switch(win_t *win)
{
	sfColor color = sfColor_fromRGBA(0, 0, 0, 75);
	win->quest_book.rect[0] = sfRectangleShape_create();
	win->quest_book.rect[1] = sfRectangleShape_create();
	sfRectangleShape_setFillColor(win->quest_book.rect[0], color);
	sfRectangleShape_setFillColor(win->quest_book.rect[1], color);
	sfRectangleShape_setSize(win->quest_book.rect[0],
	(sfVector2f){40, 40});
	sfRectangleShape_setSize(win->quest_book.rect[1],
	(sfVector2f){41, 40});
	sfRectangleShape_setPosition(win->quest_book.rect[0],
	(sfVector2f){258, 566});
	sfRectangleShape_setPosition(win->quest_book.rect[1],
	(sfVector2f){977, 566});
}

void	book_moved(win_t *win)
{
	sfVector2f evt = {win->evt.mouseMove.x, win->evt.mouseMove.y};

	win->quest_book.state[1] = 0;
	win->quest_book.state[2] = 0;
	if (evt.x >= 258 && evt.x <= 298 && evt.y >= 566 && evt.y <= 606)
		win->quest_book.state[1] = 1;
	if (evt.x >= 977 && evt.x <= 1017 && evt.y >= 566 && evt.y <= 606)
		win->quest_book.state[2] = 1;
}

void	book_released(win_t *win)
{
	sfVector2f evt = {win->evt.mouseButton.x, win->evt.mouseButton.y};

	if (evt.x >= 258 && evt.x <= 298 && evt.y >= 566 && evt.y <= 606 &&
	win->quest_book.page > 1) {
		play_sound(win, 3);
		win->quest_book.page -= 1;
	}
	if (evt.x >= 977 && evt.x <= 1017 && evt.y >= 566 && evt.y <= 606 &&
	win->quest_book.page < (win->quest_book.max_page + 1) / 2) {
		play_sound(win, 3);
		win->quest_book.page += 1;
	}
}

void	book_events(win_t *win)
{
	if (win->quest_book.state[0] == -1)
		return;
	switch (win->evt.type) {
		case (sfEvtMouseMoved):
			book_moved(win);
			break;
		case (sfEvtMouseButtonReleased):
			book_released(win);
			break;
	}
}
