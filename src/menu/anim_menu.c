/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	blink_cursor_menu(obj_t *cursor)
{
	static int dir = -1;
	static int alpha = 255;
	sfColor color;

	cursor->clock.time = sfClock_getElapsedTime(cursor->clock.clock);
	cursor->clock.sec = cursor->clock.time.microseconds / 1000000.0;
	if (cursor->clock.sec >= 0.05) {
		alpha += (dir * 17);
		if (alpha <= 0 || alpha >= 255)
			dir = -dir;
		color = sfColor_fromRGBA(255, 255, 255, alpha);
		sfSprite_setColor(cursor->spt, color);
		sfClock_restart(cursor->clock.clock);
	}
}

void	set_alpha_text(win_t *win)
{
	static int a = 0;
	static int offset = 1;
	sfText_setColor(win->menu.text, (sfColor){255, 255, 255, a});

	win->menu.clock.time = sfClock_getElapsedTime(win->menu.clock.clock);
	win->menu.clock.sec = win->menu.clock.time.microseconds / 1000000.0;
	if (win->menu.clock.sec > 0.02) {
		if (offset == 1) {
			a += 5;
			if (a >= 250)
				offset = -1;
		} else if (offset == -1) {
			a -= 5;
			if (a <= 5)
				offset = 1;
		}
		sfClock_restart(win->menu.clock.clock);
	}
}

void	move_rect_menu(menu_t *menu, int offset, win_t *win, int *a)
{
	static int mul = 5;
	if (*a >= 255) {
		mul = -5;
		menu->rect.left = 1279;
	} if (*a <= 0) {
		menu->rect.left = 1280;
	}
	if (offset > 0) {
		*a += mul;
	}
}

void	move_menu(menu_t *menu, win_t *win)
{
	int max = 1280;
	static int a = 5;

	menu->clock.time = sfClock_getElapsedTime(menu->clock.clock);
	menu->clock.sec = menu->clock.time.microseconds / 1000000.0;
	if (menu->clock.sec > 0.03) {
		sfRectangleShape_setFillColor(win->background[0].rect,
			sfColor_fromRGBA(0, 0, 0, a));
		if (menu->rect.left < max && menu->rect.left >= 0)
			move_rect_menu(menu, menu->offset, win, &a);
		if (menu->rect.left >= max) {
			win->state = 4;
			sfRectangleShape_setFillColor(win->background[0].rect,
			sfColor_fromRGBA(0, 0, 0, 200));
		}
		menu->offset++;
		sfClock_restart(menu->clock.clock);
	}
}
