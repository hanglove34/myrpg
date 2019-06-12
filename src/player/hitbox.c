/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	hitbox_up(win_t *win, monster_t *tmp)
{
	if (tmp->monster->pos.x > win->heros.pos.x - 78 &&
		tmp->monster->pos.x < win->heros.pos.x + 78) {
		if (tmp->monster->pos.y > win->heros.pos.y - 78 &&
			tmp->monster->pos.y < win->heros.pos.y) {
			tmp->monster->stat.hp -= (win->heros.stat.stat_end[2])
			/ (1 + (tmp->monster->stat.armor /500));
			change_damage(tmp, win, (win->heros.stat.stat_end[2])
			/ (1 + (tmp->monster->stat.armor /500)));
			change_print_bar(tmp, win);
			add_xp(win, tmp);
		}
	}
}

void	hitbox_down(win_t *win, monster_t *tmp)
{
	if (tmp->monster->pos.x > win->heros.pos.x - 78 &&
		tmp->monster->pos.x < win->heros.pos.x + 78) {
		if (tmp->monster->pos.y > win->heros.pos.y &&
		tmp->monster->pos.y < win->heros.pos.y + 78) {
			tmp->monster->stat.hp -= (win->heros.stat.stat_end[2])
			/ (1 + (tmp->monster->stat.armor /500));
			change_damage(tmp, win, (win->heros.stat.stat_end[2])
			/ (1 + (tmp->monster->stat.armor /500)));
			change_print_bar(tmp, win);
			add_xp(win, tmp);
		}
	}
}

void	hitbox_right(win_t *win, monster_t *tmp)
{
	if (tmp->monster->pos.x > win->heros.pos.x &&
		tmp->monster->pos.x < win->heros.pos.x + 78) {
		if (tmp->monster->pos.y > win->heros.pos.y - 78
		&& tmp->monster->pos.y < win->heros.pos.y + 78) {
			tmp->monster->stat.hp -= (win->heros.stat.stat_end[2])
			/ (1 + (tmp->monster->stat.armor /500));
			change_damage(tmp, win, (win->heros.stat.stat_end[2])
			/ (1 + (tmp->monster->stat.armor /500)));
			change_print_bar(tmp, win);
			add_xp(win, tmp);
		}
	}
}

void	hitbox_left(win_t *win, monster_t *tmp)
{
	if (tmp->monster->pos.x > win->heros.pos.x - 78 &&
		tmp->monster->pos.x < win->heros.pos.x) {
		if (tmp->monster->pos.y > win->heros.pos.y - 78 &&
			tmp->monster->pos.y < win->heros.pos.y + 78) {
			tmp->monster->stat.hp -= (win->heros.stat.stat_end[2])
			/ (1 + (tmp->monster->stat.armor /500));
			change_damage(tmp, win, (win->heros.stat.stat_end[2])
			/ (1 + (tmp->monster->stat.armor /500)));
			change_print_bar(tmp, win);
			add_xp(win, tmp);
		}
	}
}
