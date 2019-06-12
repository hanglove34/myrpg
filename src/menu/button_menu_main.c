/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** rpg
*/

#include "my.h"

void	up_music(win_t *win, scene_t *scene)
{
	(void) scene;
	if (win->volmusic < 100)
		win->volmusic += 25;
	sfMusic_setVolume(win->music[win->num_music].music, win->volmusic);

}

void	less_music(win_t *win, scene_t *scene)
{
	(void) scene;
	if (win->volmusic > 0)
		win->volmusic -= 25;
	sfMusic_setVolume(win->music[win->num_music].music, win->volmusic);
}

void	settings_button(win_t *win, scene_t *scene)
{
	(void) scene;
	if (win->ver[3] == 0)
		win->ver[3] = 1;
	else
		win->ver[3] = 0;
}

void	exit_button(win_t *win, scene_t *scene)
{
	(void) scene;
	sfRenderWindow_close(win->win);
}

void	play_button(win_t *win, scene_t *scene)
{
	(void) scene;
	win->state = 0;
	win->ver[3] = 0;
	play_music(win, 0, 2);
	change_pos_button(win);
	sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
	get_cine_num(win, scene[win->scene], 1);
}
