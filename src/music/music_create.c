/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	init_sound(win_t *win)
{
	win->sound = malloc(sizeof(*win->music) * 5);
	win->sound[0].music =
	sfMusic_createFromFile("img/walk.ogg");
	win->sound[1].music =
	sfMusic_createFromFile("img/sell:buy.ogg");
	win->sound[2].music =
	sfMusic_createFromFile("img/sword.ogg");
	win->sound[3].music =
	sfMusic_createFromFile("img/turn_page.ogg");
	win->sound[4].music =
	sfMusic_createFromFile("img/inventory.ogg");
}

void	init_music_menu(win_t *win)
{
	win->music = malloc(sizeof(*win->music) * 3);
	win->num_music = 2;
	win->music[0].music =
	sfMusic_createFromFile("img/RPG_The_Secret_Within.ogg");
	win->music[1].music =
	sfMusic_createFromFile("img/Ove_Earth_Is_All_We_Have.ogg");
	win->music[2].music =
	sfMusic_createFromFile("img/Ove_Melaa_Heaven_Sings.ogg");
	sfMusic_play(win->music[2].music);
	sfMusic_setVolume(win->music[2].music, 50.0);
	sfMusic_setLoop(win->music[2].music, sfTrue);
	init_sound(win);
}

void	free_music(win_t *win)
{
	for (int i = 0; i < 3; i++) {
		sfMusic_stop(win->music[i].music);
		sfMusic_destroy(win->music[i].music);
	}
	for (int i = 0; i < 5; i++) {
		sfMusic_stop(win->sound[i].music);
		sfMusic_destroy(win->sound[i].music);
	}
	free(win->sound);
	free(win->music);
}

void	play_music(win_t *win, int nb, int stop)
{
	sfMusic_stop(win->music[stop].music);
	win->num_music = nb;
	sfMusic_play(win->music[nb].music);
	sfMusic_setVolume(win->music[nb].music, win->volmusic);
	sfMusic_setLoop(win->music[nb].music, sfTrue);
}

void	play_sound(win_t *win, int nb)
{
	sfMusic_play(win->sound[nb].music);
	sfMusic_setVolume(win->sound[nb].music, win->volmusic);
}
