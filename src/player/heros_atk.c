/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	check_up(win_t *win, monster_t *monster)
{
	monster_t *tmp = monster;
	while (tmp->next) {
		if (tmp->monster->stat.hp > 0) {
			hitbox_up(win, tmp);
		}
		tmp = tmp->next;
	}
}

void	check_down(win_t *win, monster_t *monster)
{
	monster_t *tmp = monster;
	while (tmp->next) {
		if (tmp->monster->stat.hp > 0) {
			hitbox_down(win, tmp);
		}
		tmp = tmp->next;
	}
}

void	check_left(win_t *win, monster_t *monster)
{
	monster_t *tmp = monster;
	while (tmp->next) {
		if (tmp->monster->stat.hp > 0) {
			hitbox_left(win, tmp);
		}
		tmp = tmp->next;
	}
}

void	check_right(win_t *win, monster_t *monster)
{
	monster_t *tmp = monster;
	while (tmp->next) {
		if (tmp->monster->stat.hp > 0) {
			hitbox_right(win, tmp);
		}
		tmp = tmp->next;
	}
}

void	choose_hitbox(win_t *win, monster_t *monster, int save)
{
	for (int i = 0; i < 4 && win->heros.state[5] == 0; i++) {
		win->heros.state[5] = 1;
		switch (save) {
			case 0:
				check_down(win, monster);
				break;
			case 1:
				check_left(win, monster);
				break;
			case 2:
				check_right(win, monster);
				break;
			case 3:
				check_up(win, monster);
				break;
		}
	}
}
