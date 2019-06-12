/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	init_quest_book_status_discovered(win_t *win)
{
	win->quest_book.status_txt[2] = sfText_create();
	sfText_setFont(win->quest_book.status_txt[2], win->font);
	sfText_setColor(win->quest_book.status_txt[2], sfBlack);
	sfText_setString(win->quest_book.status_txt[2], "Not discovered yet.");
	sfText_setCharacterSize(win->quest_book.status_txt[2], 32);
	sfText_setPosition(win->quest_book.status_txt[2],
	(sfVector2f){310, 300});
	sfText_setStyle(win->quest_book.status_txt[2], sfTextBold);
	win->quest_book.status_txt[3] = sfText_create();
	sfText_setFont(win->quest_book.status_txt[3], win->font);
	sfText_setColor(win->quest_book.status_txt[3], sfBlack);
	sfText_setString(win->quest_book.status_txt[3], "Not discovered yet.");
	sfText_setCharacterSize(win->quest_book.status_txt[3], 32);
	sfText_setPosition(win->quest_book.status_txt[3],
	(sfVector2f){705, 300});
	sfText_setStyle(win->quest_book.status_txt[3], sfTextBold);
}

void	init_quest_book_status(win_t *win)
{
	win->quest_book.status_txt[0] = sfText_create();
	sfText_setFont(win->quest_book.status_txt[0], win->font);
	sfText_setCharacterSize(win->quest_book.status_txt[0], 26);
	sfText_setColor(win->quest_book.status_txt[0], sfBlack);
	sfText_setString(win->quest_book.status_txt[0], "Status :");
	sfText_setPosition(win->quest_book.status_txt[0],
	(sfVector2f){320, 390});
	sfText_setStyle(win->quest_book.status_txt[0], sfTextBold);
	win->quest_book.status_txt[1] = sfText_create();
	sfText_setFont(win->quest_book.status_txt[1], win->font);
	sfText_setCharacterSize(win->quest_book.status_txt[1], 26);
	sfText_setColor(win->quest_book.status_txt[1], sfBlack);
	sfText_setString(win->quest_book.status_txt[1], "Status :");
	sfText_setPosition(win->quest_book.status_txt[1],
	(sfVector2f){720, 390});
	sfText_setStyle(win->quest_book.status_txt[1], sfTextBold);
}

void	init_quest_book_rewards(win_t *win)
{
	win->quest_book.reward_txt[0] = sfText_create();
	sfText_setFont(win->quest_book.reward_txt[0], win->font);
	sfText_setCharacterSize(win->quest_book.reward_txt[0], 40);
	sfText_setColor(win->quest_book.reward_txt[0], sfBlack);
	sfText_setString(win->quest_book.reward_txt[0], "Rewards :");
	sfText_setPosition(win->quest_book.reward_txt[0],
	(sfVector2f){300, 430});
	sfText_setStyle(win->quest_book.reward_txt[0], sfTextBold);
	win->quest_book.reward_txt[1] = sfText_create();
	sfText_setFont(win->quest_book.reward_txt[1], win->font);
	sfText_setCharacterSize(win->quest_book.reward_txt[1], 40);
	sfText_setColor(win->quest_book.reward_txt[1], sfBlack);
	sfText_setString(win->quest_book.reward_txt[1], "Rewards :");
	sfText_setPosition(win->quest_book.reward_txt[1],
	(sfVector2f){690, 430});
	sfText_setStyle(win->quest_book.reward_txt[1], sfTextBold);
}

void	init_quest_book_str(win_t *win)
{
	quest_t *tmp = win->quest;

	for (int i = 0; tmp; tmp = tmp->next, i++) {
		win->quest_book.quest_txt[i] = sfText_create();
		win->quest_book.page_nb[i] = sfText_create();
		sfText_setFont(win->quest_book.page_nb[i], win->font);
		sfText_setCharacterSize(win->quest_book.page_nb[i], 28);
		sfText_setColor(win->quest_book.page_nb[i], sfBlack);
		sfText_setString(win->quest_book.page_nb[i], my_getstr(i + 1));
		sfText_setPosition(win->quest_book.page_nb[i], (i % 2 == 0) ?
		(sfVector2f){420, 120} : (sfVector2f){830, 120});
		sfText_setStyle(win->quest_book.page_nb[i], sfTextBold);
		sfText_setFont(win->quest_book.quest_txt[i], win->font);
		sfText_setCharacterSize(win->quest_book.quest_txt[i], 28);
		sfText_setColor(win->quest_book.quest_txt[i], sfBlack);
		sfText_setString(win->quest_book.quest_txt[i],
		tmp->longer_str);
		sfText_setPosition(win->quest_book.quest_txt[i], (i % 2 == 0) ?
		(sfVector2f){300, 180} : (sfVector2f){690, 180});
	}
}

void	init_quest_book(win_t *win)
{
	win->quest_book.tex = sfTexture_createFromFile("img/book.png", NULL);
	win->quest_book.spr = sfSprite_create();
	sfSprite_setTexture(win->quest_book.spr, win->quest_book.tex, sfTrue);
	sfSprite_setOrigin(win->quest_book.spr, (sfVector2f){300, 232});
	sfSprite_setScale(win->quest_book.spr, (sfVector2f){1.5, 1.5});
	sfSprite_setPosition(win->quest_book.spr, (sfVector2f){640, 360});
	win->quest_book.state[0] = -1;
	win->quest_book.state[1] = 0;
	win->quest_book.state[2] = 0;
	win->quest_book.page = 1;
	win->quest_book.max_page = 5;
	init_quest_book_str(win);
	init_quest_book_rewards(win);
	init_quest_book_status(win);
	init_quest_book_status_discovered(win);
	init_book_switch(win);
	attrib_rewards_quest_one(win);
	attrib_rewards_quest_two(win);
	attrib_rewards_quest_three(win);
	attrib_rewards_quest_four(win);
}
