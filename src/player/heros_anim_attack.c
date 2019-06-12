/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	move_rect_attack(obj_t *heros, int offset)
{
	static int move = 130;
	if (offset > 0)
		heros->rect.left += move;
	if (heros->rect.left >= 768) {
		heros->state[5] = -1;
		heros->rect.left = 0;
	}
}

void	player_attack(obj_t *heros)
{
	heros->clock.time = sfClock_getElapsedTime(heros->clock.clock);
	heros->clock.sec = heros->clock.time.microseconds / 1000000.0;
	if (heros->clock.sec > 0.1) {
		move_rect_attack(heros, heros->offset);
		heros->offset++;
		sfClock_restart(heros->clock.clock);
	}
	sfSprite_setPosition(heros->spt, heros->pos);
}
