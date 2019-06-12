/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	lunch_spell(obj_t *spell, int status, win_t *win)
{
	if (spell->state[0] == -1) {
		spell->pos.x = win->heros.pos.x;
		spell->pos.y = win->heros.pos.y - 40;
		spell->state[0] = status;
		sfSprite_setOrigin (spell->spt, (sfVector2f){50, 60});
		switch (spell->state[0]) {
			case 0:
				sfSprite_setRotation(spell->spt, (float)90);
				break;
			case 1:
				sfSprite_setRotation(spell->spt, (float)180);
				break;
			case 2:
				sfSprite_setRotation(spell->spt, (float)0);
				break;
			case 3:
				sfSprite_setRotation(spell->spt, (float)-90);
		}
		sfSprite_setPosition(spell->spt, spell->pos);
	}
}

void	move_rect_spell(obj_t *spell, int offset, win_t *win)
{
	if (offset > 0)
		spell->rect.left += 120;
	if (spell->rect.left >= spell->rect.width * 11) {
		spell->rect.left = 0;
		spell->state[0] = -1;
		win->heros.state[6] = -1;
	}
}

void	anim_spell(obj_t *spell, win_t *win)
{
	spell->clock.time =
	sfClock_getElapsedTime(spell->clock.clock);
	spell->clock.sec =
	spell->clock.time.microseconds / 1000000.0;
	if (spell->clock.sec > 0.10) {
		move_rect_spell(spell, spell->offset, win);
		spell->offset++;
		sfClock_restart(spell->clock.clock);
	}
	sfSprite_setTextureRect(spell->spt, spell->rect);
}

void	move_spell(obj_t *spell)
{
	switch (spell->state[0]) {
		case 0:
			spell->pos.y += 6;
			break;
		case 1:
			spell->pos.x -= 6;
			break;
		case 2:
			spell->pos.x += 6;
			break;
		case 3:
			spell->pos.y -= 6;
			break;
	}
	sfSprite_setPosition(spell->spt, spell->pos);
}

void	draw_spell(win_t *win, obj_t *spell)
{
	if (win->heros.state[6] >= 0)
		lunch_spell(spell, win->heros.ver, win);
	if (spell->state[0] != -1) {
		anim_spell(spell, win);
		move_spell(spell);
		sfRenderWindow_drawSprite(win->win, spell->spt, NULL);
	}
}
