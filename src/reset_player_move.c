/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "my.h"

void	reset_player_move(win_t *win)
{
	int i = 0;

	while (i < 4) {
		win->heros.state[i] = -1;
		i++;
	}
}
