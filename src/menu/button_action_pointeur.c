/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** nico pls
*/

#include "my.h"

void	credit(win_t *win, scene_t *s)
{
	if (win->state != 5)
		win->state = 5;
	else if (win->state == 5)
		win->state = 4;
}

void	move_print_credits(char **str, win_t *win, int fd, int *state)
{
	char *str2;
	clck_t *clck = &win->menu.clock;
	clck->time = sfClock_getElapsedTime(clck->clock);
	clck->sec = clck->time.microseconds / 1000000.0;
	if (clck->sec > 4 || *state == 0) {
		if (*state > 0)
			free(*str);
		for (int i = 0; i < *state; i++)
			get_next_line(fd);
		str2 = get_next_line(fd);
		if (str2 == NULL) {
			*state = 0;
			win->state = 4;
			return;
		} for (int i = 0; str2 && i < 5; i++) {
			go_to_next_line(state, str, fd, str2);
			str2 = get_next_line(fd);
		}
		sfClock_restart(clck->clock);
	}
}

void	draw_credits(win_t *win)
{
	static int state = 0;
	sfText *text = create_text("\0",
	(sfVector2f){740, 206}, win);
	sfText_setColor(text, sfBlack);
	static char *str;
	int fd = open("other/credits", O_RDONLY);
	while (fd == -1)
		return;
	move_print_credits(&str, win, fd, &state);
	sfText_setString(text, str);
	sfRenderWindow_drawText(win->win, text, NULL);
	close(fd);
}

void	back_to_the_menu(win_t *win, scene_t *scene)
{
	win->state = 4;
	win->ver[3] = 0;
	(void) scene;
	play_music(win, 2, win->num_music);
	replace_settings_menu(win);
}

void	continue_the_game(win_t *win, scene_t *scene)
{
	win->state = 0;
	play_music(win, 0, win->num_music);
	load(scene, win);
	change_pos_button(win);
}
