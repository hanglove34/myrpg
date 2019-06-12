/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	load_monsters(scene_t *scene, win_t *win, int fd, int i)
{
	float fl;
	int nb;

	for (monster_t *tmp = scene[i].monster; tmp && tmp->next;
	tmp = tmp->next) {
		read(fd, &fl, sizeof(float));
		tmp->monster->pos.x = fl;
		read(fd, &fl, sizeof(float));
		tmp->monster->pos.y = fl;
		sfSprite_setPosition(tmp->monster->spt, tmp->monster->pos);
		read(fd, &fl, sizeof(float));
		tmp->monster->pos_tile.x = fl;
		read(fd, &fl, sizeof(float));
		tmp->monster->pos_tile.y = fl;
		read(fd, &nb, 4);
		tmp->monster->stat.hp = nb;
		change_print_bar(tmp, win);
	}
}

void	load_npc(scene_t *scene, win_t *win, int fd, int i)
{
	float fl;

	for (npc_t *npc = scene[i].npc; npc; npc = npc->next) {
		npc->tree = NULL;
		new_npc_dial(npc);
		read(fd, &fl, sizeof(float));
		npc->pos.x = fl;
		read(fd, &fl, sizeof(float));
		npc->pos.y = fl;
		sfSprite_setPosition(npc->spr, npc->pos);
	}
	skip_dialogues(scene[i].npc, win->quest);
}

void	load_scene(scene_t *scene, win_t *win, int fd, int i)
{
	int nb;
	float fl;

	read(fd, &nb, 4);
	if (nb != 0 && scene[i].init == 0)
		init_targeted_scenes("other/scene", i, win, scene);
	scene[i].init = nb;
	if (nb != 0) {
		read(fd, &fl, sizeof(float));
		scene[i].map->tr.x = fl;
		read(fd, &fl, sizeof(float));
		scene[i].map->tr.y = fl;
		load_npc(scene, win, fd, i);
		load_monsters(scene, win, fd, i);
	}
}
