/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	load_quest(win_t *win, int fd)
{
	int nb;

	for (quest_t *tmp = win->quest; tmp; tmp = tmp->next) {
		read(fd, &nb, 4);
		tmp->nb = nb;
		read(fd, &nb, 4);
		tmp->state = nb;
	}
}

void	load_pos(win_t *win, int fd)
{
	int nb;
	float fl;

	read(fd, &nb, 4);
	win->scene = nb;
	read(fd, &nb, 4);
	win->heros.stat.gold = nb;
	read(fd, &nb, 4);
	win->heros.stat.all_hp = nb;
	read(fd, &nb, 4);
	win->heros.stat.stat_end[0] = nb;
}

void	load_stats(win_t *win, int fd)
{
	int nb;
	read(fd, &nb, 4);
	win->heros.stat.stat_end[1] = nb;
	read(fd, &nb, 4);
	win->heros.stat.stat_end[2] = nb;
	read(fd, &nb, 4);
	win->heros.stat.stat_end[3] = nb;
	read(fd, &nb, 4);
	win->heros.stat.stat_end[4] = nb;
	read(fd, &nb, 4);
	win->heros.stat.stat_end[5] = nb;
	read(fd, &nb, 4);
	win->heros.stat.xp[0] = nb;
	change_xp_bar(win);
	read(fd, &nb, 4);
	win->heros.stat.lvl = nb;
	for (int i = 1; i != 31; i++) {
		read(fd, &nb, 4);
		win->invent[i].state[0] = nb;
	}
}

int	load(scene_t *scene, win_t *win)
{
	int nb_magic;
	int fd = open("other/save.txt", O_RDONLY);
	float fl;
	int rd;

	rd = read(fd, &nb_magic, 4);
	if (fd == -1 || rd == 0 || rd == -1 || nb_magic != 0xabcde)
		return (-1);
	load_pos(win, fd);
	load_stats(win, fd);
	load_quest(win, fd);
	for (int i = 0; i < NB_SCENE; i++)
		load_scene(scene, win, fd, i);
	read(fd, &fl, sizeof(float));
	win->heros.pos.x = fl;
	read(fd, &fl, sizeof(float));
	win->heros.pos.y = fl;
	win->purse = NULL;
	close(fd);
	return (0);
}
