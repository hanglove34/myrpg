/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	validate_quests(win_t *win, scene_t *scene)
{
	quest_t *tmp = win->quest;

	draw_quests(win);
	while (tmp) {
		if (tmp->state > 0)
			enable_tp(scene, tmp);
		if (tmp->state == 1)
			tmp->valid(win, tmp, scene);
		tmp = tmp->next;
	}
}

void	valid_quest_one(win_t *win, quest_t *quest, scene_t *scene)
{
	npc_t *tmp;

	tmp = find_npc(scene[win->scene].npc, 2);
	if (tmp && tmp->active == 1) {
		quest->state = 3;
		win_give_item(win, 1);
		win_give_item(win, 2);
	}
}

void	valid_quest_two(win_t *win, quest_t *quest, scene_t *scene)
{
	static int i = 0;
	npc_t *tmp = tmp = find_npc(scene[win->scene].npc, 1);
	quest_t *tmp_quest = find_quest(quest, 2);
	monster_t *tmp_monster = scene[win->scene].monster;

	if (i == 0 && tmp_quest->state == 1) {
		tmp->state[2] = 2;
		i += 1;
	}
	while (tmp_monster && tmp_monster->next) {
		if (tmp_monster->monster->stat.hp <= 0) {
			tmp_quest->state = 3;
			win->heros.stat.gold += 25;
			remove_all_quest_node_in_scene(scene, 2);
		}
		tmp_monster = tmp_monster->next;
	}
}

void	valid_quest_three(win_t *win, quest_t *quest, scene_t *scene)
{
	npc_t *tmp;

	if (win->scene == 2) {
		quest->state = 3;
		win->heros.stat.gold += 25;
		remove_all_quest_node_in_scene(scene, 3);
	}
}

void	valid_quest_four(win_t *win, quest_t *quest, scene_t *scene)
{
	npc_t *tmp;

	if (win->state == -3) {
		quest->state = 3;
		win->heros.stat.gold += 25;
		remove_all_quest_node_in_scene(scene, 4);
	}
}
