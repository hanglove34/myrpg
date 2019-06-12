/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	init_quest_fct(quest_t *new, int nb)
{
	switch (nb) {
		case (1):
			new->valid = &valid_quest_one;
			break;
		case (2):
			new->valid = &valid_quest_two;
			break;
		case (3):
			new->valid = &valid_quest_three;
			break;
		case (4):
			new->valid = &valid_quest_four;
			break;
		case (5):
			new->valid = &valid_quest_five;
			break;
	}
}

void	move_quest_rect_left(quest_t *new)
{
	if (new->rect.pos.x != -200 && new->text.pos.x != -200) {
		new->rect.pos.x -= 5;
		new->text.pos.x -= 5;
		sfText_setPosition(new->text.txt, new->text.pos);
		sfRectangleShape_setPosition(new->rect.rect, new->rect.pos);
	}
}

void	move_quest_rect_right(quest_t *new)
{
	if (new->rect.pos.x != 0 && new->text.pos.x != 0) {
		new->rect.pos.x += 5;
		new->text.pos.x += 5;
		sfText_setPosition(new->text.txt, new->text.pos);
		sfRectangleShape_setPosition(new->rect.rect, new->rect.pos);
	}
}

void	init_quest_rect(quest_t *new)
{
	sfColor fill_col = sfColor_fromRGBA(0, 0, 0, 150);
	new->rect.pos = (sfVector2f){-200, 150};
	new->rect.size = (sfVector2f){200, 40};
	new->rect.rect = sfRectangleShape_create();
	sfRectangleShape_setSize(new->rect.rect, new->rect.size);
	sfRectangleShape_setPosition(new->rect.rect, new->rect.pos);
	sfRectangleShape_setFillColor(new->rect.rect, fill_col);
}
