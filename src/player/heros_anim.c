/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	move_rect_part(obj_t *heros, int offset)
{
	static int move = 128;
	if (offset > 0)
		heros->rect.left += move;
	if (heros->rect.left <= 384) {
		heros->rect.left = 384;
		move *= -1;
	}
	if (heros->rect.left >= 512) {
		heros->rect.left = 512;
		move *= -1;
	}
}

void	move_rect(obj_t *heros, int offset)
{
	static int move = 128;
	if (offset > 0)
		heros->rect.left += move;
	if (heros->rect.left >= 256) {
		heros->rect.left = 256;
		move *= -1;
	}
	if (heros->rect.left <= 0) {
		heros->rect.left = 0;
		move *= -1;
	}
}

void	anim_player(obj_t *heros)
{
	heros->clock.time = sfClock_getElapsedTime(heros->clock.clock);
	heros->clock.sec = heros->clock.time.microseconds / 1000000.0;
	if (heros->clock.sec > 2) {
		move_rect_part(heros, heros->offset);
		heros->offset++;
		sfClock_restart(heros->clock.clock);
	}
	sfSprite_setPosition(heros->spt, heros->pos);
}

void	move_player(obj_t *heros)
{
	heros->clock.time = sfClock_getElapsedTime(heros->clock.clock);
	heros->clock.sec = heros->clock.time.microseconds / 1000000.0;
	if (heros->clock.sec > 0.18) {
		move_rect(heros, heros->offset);
		heros->offset++;
		sfClock_restart(heros->clock.clock);
	}
	sfSprite_setPosition(heros->spt, heros->pos);
}
