/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	new_save_point(npc_t *new, win_t *win, char **tab)
{
	new->type = SAVE;
	new->rect[0] = (sfIntRect){38 * 16, 7 * 16, 16, 48};
	new->rect[1] = (sfIntRect){38 * 16, 7 * 16, 16, 48};
	new->rect[2] = (sfIntRect){38 * 16, 7 * 16, 16, 48};
	new->rect[3] = (sfIntRect){38 * 16, 7 * 16, 16, 48};
	sfSprite_setScale(new->spr, (sfVector2f){3, 3});
	sfSprite_setTextureRect(new->spr, new->rect[0]);
	sfSprite_setOrigin(new->spr, (sfVector2f){8, 48});
	sfSprite_setPosition(new->spr, new->pos);
	sfSprite_setTexture(new->dial_spr, win->item[1].img, sfTrue);
	sfSprite_setScale(new->dial_spr, (sfVector2f){10, 10});
	sfSprite_setTextureRect(new->dial_spr, (sfIntRect){96, 32, 32, 32});
	sfSprite_setOrigin(new->dial_spr, (sfVector2f){16, 32});
	sfSprite_setPosition(new->dial_spr, (sfVector2f){200, 560});
}

void	answer_save_point(scene_t *scene, win_t *win)
{
	if (win->ver[2] == 1)
		save(scene, win);
}
