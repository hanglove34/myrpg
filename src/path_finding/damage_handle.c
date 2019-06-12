/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	change_print_bar(monster_t *tmp, win_t *win)
{
	float rect = tmp->hp.size.x;
	float hp = tmp->monster->stat.hp;
	float hp_max = tmp->monster->stat.all_hp;
	rect = 70 * (hp / hp_max);
	tmp->hp.size.x = rect;
	sfRectangleShape_setSize(tmp->hp.rect, tmp->hp.size);
}

void	heros_take_damage(monster_t *tmp, win_t *win)
{
	int damage =  tmp->monster->stat.atk / (1 +
	(win->heros.stat.armor /500));
	while (damage > 0 && win->heros.stat.stat_end[0] > 0) {
		win->heros.stat.stat_end[0]--;
		damage--;
		if (win->heros.stat.stat_end[0] == 0)
			win->state = -42;
	}
}

void	ia_attack(win_t *win, monster_t *monster)
{
	monster->clock.time = sfClock_getElapsedTime(monster->clock.clock);
	monster->clock.sec = monster->clock.time.microseconds / 1000000.0;
	if (monster->clock.sec > 0.5) {
		heros_take_damage(monster, win);
		sfClock_restart(monster->clock.clock);
	}
}

void	move_ia_cam(monster_t *monster, sfVector2f offset)
{
	monster_t *tmp = monster;
	while (tmp->next && tmp) {
		tmp->monster->pos.x += offset.x;
		tmp->monster->pos.y += offset.y;
		tmp->monster->pos_tile.x += offset.x;
		tmp->monster->pos_tile.y += offset.y;
		sfRectangleShape_setPosition(tmp->hp.rect,
		(sfVector2f){tmp->monster->pos.x - 35, tmp->monster->pos.y -
		tmp->monster->rect.height});
		sfRectangleShape_setPosition(tmp->hp2.rect,
		(sfVector2f){tmp->monster->pos.x - 35, tmp->monster->pos.y -
		tmp->monster->rect.height});
		sfSprite_setPosition(tmp->monster->spt, tmp->monster->pos);
		sfSprite_setTextureRect(tmp->monster->spt, tmp->monster->rect);
		tmp = tmp->next;
	}
}

void	print_ai(win_t *win, monster_t *monster)
{
	monster_t *tmp = monster;
	while (tmp->next && tmp) {
		if (tmp->monster->stat.hp > 0) {
			sfRenderWindow_drawRectangleShape(win->win,
			tmp->hp2.rect, NULL);
			sfRenderWindow_drawRectangleShape(win->win,
			tmp->hp.rect, NULL);
			print_damage(tmp, win);
		}
		tmp = tmp->next;
	}
}
