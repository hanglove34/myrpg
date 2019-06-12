/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	move_rect_ia_attack(monster_t *tmp, int offset)
{
	if (offset > 0)
		tmp->monster->rect.left += (tmp->monster->rect.width);
	if (tmp->monster->rect.left >= tmp->monster->rect.width * 6) {
		tmp->monster->rect.left = 0;
	}
}

void	anim_ia_attack(monster_t *tmp)
{
	tmp->monster->clock.time =
	sfClock_getElapsedTime(tmp->monster->clock.clock);
	tmp->monster->clock.sec =
	tmp->monster->clock.time.microseconds / 1000000.0;
	if (tmp->monster->rect.left <= tmp->monster->rect.width * 2)
		tmp->monster->rect.left = tmp->monster->rect.width * 3;
	if (tmp->monster->clock.sec > 0.20) {
		move_rect_ia_attack(tmp, tmp->monster->offset);
		tmp->monster->offset++;
		sfClock_restart(tmp->monster->clock.clock);
	}
	sfSprite_setPosition(tmp->monster->spt, tmp->monster->pos);
}


void	move_rect_ia(monster_t *tmp, int offset)
{
	if (offset > 0)
		tmp->monster->rect.left += (tmp->monster->rect.width *
		tmp->mul);
	if (tmp->monster->rect.left >= tmp->monster->rect.width * 2)
		tmp->mul = -1;
	while (tmp->monster->rect.left <= 0) {
		tmp->mul = 1;
		break;
	}
}

void	anim_ia(monster_t *tmp)
{
	tmp->monster->clock.time =
	sfClock_getElapsedTime(tmp->monster->clock.clock);
	tmp->monster->clock.sec =
	tmp->monster->clock.time.microseconds / 1000000.0;
	if (tmp->monster->clock.sec > 0.15) {
		move_rect_ia(tmp, tmp->monster->offset);
		tmp->monster->offset++;
		sfClock_restart(tmp->monster->clock.clock);
	}
	sfSprite_setPosition(tmp->monster->spt, tmp->monster->pos);
}
