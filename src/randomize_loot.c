/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** dzqsfgezq
*/

#include "my.h"

int	choose_loot(void)
{
	int n = rand() % 100;
	while (n >= 0 && n < 45)
		return (6);
	while (n >= 45 && n < 60)
		return (1);
	while (n >= 60 && n < 75)
		return (2);
	while (n >= 75 && n < 85)
		return (4);
	while (n >= 85 && n < 95)
		return (5);
	while (n >= 95 && n < 98)
		return (5);
	while (n >= 98 && n < 100)
		return (3);
}

int	*gene_item(win_t *win)
{
	int n = (rand() % 3) + 2;
	int *loot = malloc(sizeof(int) * n);
	int i = 0;
	for (i = 0; i < n - 1; i++)
		loot[i] = choose_loot();
	loot[i] = -1;
	return (loot);
}
