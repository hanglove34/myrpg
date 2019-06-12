/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	place_pnj_act_one(win_t *win, scene_t *scene)
{
	reset_value(win);
	win->heros.pos.x = 658;
	win->heros.pos.y = 396;
	scene->map->tr.x = -40;
	scene->map->tr.y = -319;
	refresh_map_vtx_arr(scene->map->vtx_arr, scene->map);
	sfSprite_setPosition(win->heros.spt, win->heros.pos);
	npc_t *npc = find_npc(scene->npc, 15);
	npc->pos.x = (658);
	npc->pos.y = (280);
	sfSprite_setPosition(npc->spr, npc->pos);
	npc = find_npc(scene->npc, 13);
	npc->pos.x = (598);
	npc->pos.y = (170);
	sfSprite_setPosition(npc->spr, npc->pos);
	npc = find_npc(scene->npc, 14);
	npc->pos.x = (718);
	npc->pos.y = (170);
	sfSprite_setPosition(npc->spr, npc->pos);
}

void	place_pnj_act_two(win_t *win, scene_t *scene)
{
	reset_value(win);
	win->heros.pos.x = 620;
	win->heros.pos.y = 366;
	scene->map->tr.x = -40;
	scene->map->tr.y = -517;
	refresh_map_vtx_arr(scene->map->vtx_arr, scene->map);
	sfSprite_setPosition(win->heros.spt, win->heros.pos);
	npc_t *npc = find_npc(scene->npc, 26);
	npc->pos.x = (500);
	npc->pos.y = (600 + scene->map->tr.y);
	sfSprite_setPosition(npc->spr, npc->pos);
	npc = find_npc(scene->npc, 27);
	npc->pos.x = (600);
	npc->pos.y = (600 + scene->map->tr.y);
	sfSprite_setPosition(npc->spr, npc->pos);
	npc = find_npc(scene->npc, 28);
	npc->pos.x = (700);
	npc->pos.y = (600 + scene->map->tr.y);
	sfSprite_setPosition(npc->spr, npc->pos);
}
