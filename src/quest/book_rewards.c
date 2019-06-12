/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	attrib_rewards_quest_five(win_t *win)
{
	int i = 0;
	win->quest_book.rewards[4] = malloc(sizeof(sfSprite *) * 5);
	for (i = 0; i < 5; i++) {
		win->quest_book.rewards[4][i] = sfSprite_create();
		sfSprite_setTexture(win->quest_book.rewards[4][i],
		win->item[8 + i].img, sfTrue);
		sfSprite_setScale(win->quest_book.rewards[4][i],
		(sfVector2f){1.5, 1.5});
		sfSprite_setTextureRect(win->quest_book.rewards[4][i],
		win->item[8 + i].rect);
		sfSprite_setPosition(win->quest_book.rewards[4][i],
		(sfVector2f){300 + (50 * i), 485});
	}
	win->quest_book.nb_rewards[4] = 5;
}

void	attrib_rewards_quest_four(win_t *win)
{
	win->quest_book.rewards[3] = malloc(sizeof(sfSprite *) * 1);
	win->quest_book.rewards[3][0] = sfSprite_create();
	sfSprite_setTexture(win->quest_book.rewards[3][0], win->pict[6].img,
	sfTrue);
	sfSprite_setScale(win->quest_book.rewards[3][0],
	(sfVector2f){1.5, 1.5});
	sfSprite_setTextureRect(win->quest_book.rewards[3][0],
	win->pict[6].rect);
	sfSprite_setPosition(win->quest_book.rewards[3][0],
	(sfVector2f){710, 485});
	win->quest_book.nb_rewards[3] = 1;
	attrib_rewards_quest_five(win);
}

void	attrib_rewards_quest_three(win_t *win)
{
	win->quest_book.rewards[2] = malloc(sizeof(sfSprite *) * 1);
	win->quest_book.rewards[2][0] = sfSprite_create();
	sfSprite_setTexture(win->quest_book.rewards[2][0], win->pict[6].img,
	sfTrue);
	sfSprite_setScale(win->quest_book.rewards[2][0],
	(sfVector2f){1.5, 1.5});
	sfSprite_setTextureRect(win->quest_book.rewards[2][0],
	win->pict[6].rect);
	sfSprite_setPosition(win->quest_book.rewards[2][0],
	(sfVector2f){300, 485});
	win->quest_book.nb_rewards[2] = 1;
}

void	attrib_rewards_quest_two(win_t *win)
{
	win->quest_book.rewards[1] = malloc(sizeof(sfSprite *) * 1);
	win->quest_book.rewards[1][0] = sfSprite_create();
	sfSprite_setTexture(win->quest_book.rewards[1][0], win->pict[6].img,
	sfTrue);
	sfSprite_setScale(win->quest_book.rewards[1][0],
	(sfVector2f){1.5, 1.5});
	sfSprite_setTextureRect(win->quest_book.rewards[1][0],
	win->pict[6].rect);
	sfSprite_setPosition(win->quest_book.rewards[1][0],
	(sfVector2f){710, 485});
	win->quest_book.nb_rewards[1] = 1;
}

void	attrib_rewards_quest_one(win_t *win)
{
	win->quest_book.rewards[0] = malloc(sizeof(sfSprite *) * 2);
	win->quest_book.rewards[0][0] = sfSprite_create();
	win->quest_book.rewards[0][1] = sfSprite_create();
	sfSprite_setTexture(win->quest_book.rewards[0][0], win->item[2].img,
	sfTrue);
	sfSprite_setTexture(win->quest_book.rewards[0][1], win->item[1].img,
	sfTrue);
	sfSprite_setScale(win->quest_book.rewards[0][0],
	(sfVector2f){1.5, 1.5});
	sfSprite_setScale(win->quest_book.rewards[0][1],
	(sfVector2f){1.5, 1.5});
	sfSprite_setTextureRect(win->quest_book.rewards[0][0],
	win->item[2].rect);
	sfSprite_setTextureRect(win->quest_book.rewards[0][1],
	win->item[1].rect);
	sfSprite_setPosition(win->quest_book.rewards[0][0],
	(sfVector2f){300, 485});
	sfSprite_setPosition(win->quest_book.rewards[0][1],
	(sfVector2f){350, 485});
	win->quest_book.nb_rewards[0] = 2;
}
