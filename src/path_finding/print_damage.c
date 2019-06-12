/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	init_print_damage(monster_t *monster, win_t *win)
{
	monster_t *tmp = monster;
	while (tmp->next) {
		tmp->alpha = 255;
		tmp->text = create_text("\0",
		(sfVector2f){tmp->monster->pos.x,
		tmp->monster->pos.y - tmp->monster->rect.height}, win);
		sfText_setStyle(tmp->text, sfTextBold);
		tmp = tmp->next;
	}
}

void	change_damage(monster_t *tmp, win_t *win, int damage)
{
	sfText_setString(tmp->text, my_getstr(damage));
	sfText_setPosition(tmp->text,
	(sfVector2f){tmp->monster->pos.x,
	tmp->monster->pos.y - (tmp->monster->rect.height)});
	tmp->pos = tmp->monster->pos.y - (tmp->monster->rect.height);
	tmp->alpha = 255;
	sfSprite_setColor(tmp->monster->spt, sfRed);
}

void	print_damage(monster_t *tmp, win_t *win)
{
	sfText_setColor(tmp->text, (sfColor){255, 0, 0, tmp->alpha});
	tmp->monster->clock.time = sfClock_getElapsedTime(
	tmp->monster->clock.clock);
	tmp->monster->clock.sec = tmp->monster->clock.time.microseconds
	/ 1000000.0;
	if (tmp->monster->clock.sec > 0.14) {
		if (tmp->alpha < 245)
			sfSprite_setColor(tmp->monster->spt, sfWhite);
		tmp->alpha -= 10;
		tmp->pos--;
		sfText_setPosition(tmp->text, (sfVector2f){tmp->monster->pos.x,
		tmp->pos});
	}
	if (tmp->alpha >= 0 && tmp->text != NULL)
		sfRenderWindow_drawText(win->win, tmp->text, NULL);
}

int	move_ia_y(monster_t *tmp)
{
	if (tmp->monster->pos.y >= tmp->monster->pos_tile.y
	+ (SCALE_MAP)) {
		tmp->monster->pos.y -= tmp->monster->stat.spd;
		tmp->monster->rect.top = tmp->monster->rect.height * 3;
	}
	if (tmp->monster->pos.y < tmp->monster->pos_tile.y) {
		tmp->monster->pos.y += tmp->monster->stat.spd;
		tmp->monster->rect.top = 0;
	}
}

int	move_ia_x(monster_t *tmp)
{
	if (tmp->monster->pos.x < tmp->monster->pos_tile.x
	+ (SCALE_MAP / 2)) {
		tmp->monster->pos.x += tmp->monster->stat.spd;
		tmp->monster->rect.top = tmp->monster->rect.height * 2;
	}
	if (tmp->monster->pos.x >= tmp->monster->pos_tile.x
	+ (SCALE_MAP / 2)) {
		tmp->monster->pos.x -= tmp->monster->stat.spd;
		tmp->monster->rect.top = tmp->monster->rect.height;
	}
}
