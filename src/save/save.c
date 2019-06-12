/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	save_stats( win_t *win, int fd)
{
	write(fd, &win->scene, 4);
	write(fd, &win->heros.stat.gold, 4);
	write(fd, &win->heros.stat.all_hp, 4);
	write(fd, &win->heros.stat.stat_end[0], 4);
	write(fd, &win->heros.stat.stat_end[1], 4);
	write(fd, &win->heros.stat.stat_end[2], 4);
	write(fd, &win->heros.stat.stat_end[3], 4);
	write(fd, &win->heros.stat.stat_end[4], 4);
	write(fd, &win->heros.stat.stat_end[5], 4);
	write(fd, &win->heros.stat.xp[0], 4);
	write(fd, &win->heros.stat.lvl, 4);
	for (int i = 1; i != 31; i++)
		write(fd, &win->invent[i].state[0], 4);
}

void	save_scene(scene_t *scene, int fd, int i)
{
	write(fd, &scene[i].init, 4);
	if (scene[i].init != 0) {
		write(fd, &scene[i].map->tr.x, sizeof(float));
		write(fd, &scene[i].map->tr.y, sizeof(float));
		for (npc_t *npc = scene[i].npc; npc; npc = npc->next) {
			write(fd, &npc->pos.x, sizeof(float));
			write(fd, &npc->pos.y, sizeof(float));
		}
		for (monster_t *mon = scene[i].monster;
		mon && mon->next; mon = mon->next) {
			write(fd, &mon->monster->pos.x, sizeof(float));
			write(fd, &mon->monster->pos.y, sizeof(float));
			write(fd, &mon->monster->pos_tile.x, sizeof(float));
			write(fd, &mon->monster->pos_tile.y, sizeof(float));
			write(fd, &mon->monster->stat.hp, 4);
		}
	}
}

int	save(scene_t *scene, win_t *win)
{
	int nb_magic = 0xabcde;
	quest_t *tmp = win->quest;
	int fd = open("other/save.txt", O_CREAT | O_WRONLY | O_TRUNC, 0744);
	write(fd, &nb_magic, 4);
	save_stats(win, fd);
	for (quest_t *tmp = win->quest; tmp; tmp = tmp->next) {
		write(fd, &tmp->nb, 4);
		write(fd, &tmp->state, 4);
	}
	for (int i = 0; i < NB_SCENE; i++)
		save_scene(scene, fd, i);
	write(fd, &win->heros.pos.x, sizeof(float));
	write(fd, &win->heros.pos.y, sizeof(float));
	close(fd);
	win->ver[2] = 0;
	return (0);
}
