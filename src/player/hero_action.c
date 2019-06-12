/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

int	cmd_atk(int *stop, sfIntRect ori, win_t *win, monster_t *monster)
{
	if (win->heros.state[5] >= 0) {
		(*stop)++;
		win->heros.rect.top = ori.top * win->heros.state[7];
		player_attack(&win->heros);
		choose_hitbox(win, monster, win->heros.state[7]);
		return (1);
	}
	return (0);
}

void	move_down(win_t *win, map_t *map, npc_t *npc, monster_t *monster)
{
	npc_t *tmp = npc;
	test_event(win, map, (sfVector2f){0, win->heros.speed + 0});
	while (test_colision_around_character(map, win, 0))
		return;
	while (test_colision(win->heros.pos, (sfVector2f){0,
	win->heros.speed + 0}, map) > 0 || in_map(win->heros.pos,
	(sfVector2f){0, win->heros.speed + 0}, map) == 0 ||
	npc_collision(tmp, win, (sfVector2f){0, 20}) == 1)
		return;
	if (move_type_y(win , map, win->heros.speed))
		win->heros.pos.y += win->heros.speed;
	else {
		map->tr.y -= win->heros.speed;
		move_npc_on_map(npc, (sfVector2f){0 , -win->heros.speed});
		move_ia_cam(monster, (sfVector2f){0, -win->heros.speed});
		move_bourse_on_map(win->purse, (sfVector2f){0 ,
		-win->heros.speed});
	}
}

void	move_left(win_t *win, map_t *map, npc_t *npc, monster_t *monster)
{
	npc_t *tmp = npc;
	test_event(win, map, (sfVector2f){-win->heros.speed - 15, 0});
	while (test_colision(win->heros.pos, (sfVector2f){
	-win->heros.speed - 15,
	0}, map) > 0 || in_map(win->heros.pos, (sfVector2f){-win->heros.speed
	- 15, 0}, map) == 0 ||
	npc_collision(tmp, win, (sfVector2f){-20, 0}) == 1)
		return;
	if (move_type_x(win , map, - win->heros.speed))
		win->heros.pos.x -= win->heros.speed;
	else {
		map->tr.x += win->heros.speed;
		move_npc_on_map(npc, (sfVector2f){win->heros.speed, 0});
		move_ia_cam(monster, (sfVector2f){win->heros.speed, 0});
		move_bourse_on_map(win->purse,
		(sfVector2f){win->heros.speed, 0});
	}
}

void	move_right(win_t *win, map_t *map, npc_t *npc, monster_t *monster)
{
	npc_t *tmp = npc;
	test_event(win, map, (sfVector2f){win->heros.speed + 14, 0});
	while (test_colision(win->heros.pos, (sfVector2f){win->heros.speed + 14,
	0}, map) > 0 || in_map(win->heros.pos, (sfVector2f){win->heros.speed +
	14, 0}, map) == 0 ||
	npc_collision(tmp, win, (sfVector2f){20, 0}) == 1)
		return;
	if (move_type_x(win , map, win->heros.speed))
		win->heros.pos.x += win->heros.speed;
	else {
		map->tr.x -= win->heros.speed;
		move_npc_on_map(npc, (sfVector2f){-win->heros.speed, 0});
		move_ia_cam(monster, (sfVector2f){-win->heros.speed, 0});
		move_bourse_on_map(win->purse,
		(sfVector2f){-win->heros.speed, 0});
	}
}

void	move_up(win_t *win, map_t *map, npc_t *npc, monster_t *monster)
{
	npc_t *tmp = npc;
	test_event(win, map, (sfVector2f){0, - win->heros.speed - 12});
	while (test_colision_around_character(map, win, 1))
		return;
	while (test_colision(win->heros.pos, (sfVector2f){0, - win->heros.speed
	- 12}, map) > 0 || in_map(win->heros.pos, (sfVector2f){0,
	- win->heros.speed - 12}, map) == 0 ||
	npc_collision(tmp, win, (sfVector2f){0, -20}) == 1)
		return;
	if (move_type_y(win , map, - win->heros.speed))
		win->heros.pos.y -= win->heros.speed;
	else {
		map->tr.y += win->heros.speed;
		move_npc_on_map(npc, (sfVector2f){0 , win->heros.speed});
		move_ia_cam(monster, (sfVector2f){0 , win->heros.speed});
		move_bourse_on_map(win->purse, (sfVector2f){0 ,
		win->heros.speed});
	}
}
