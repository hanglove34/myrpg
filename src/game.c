/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	display_cursor(win_t *win)
{
	if (win->ver[0] == 0)
		sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
	else if (win->ver[0] == 1)
		sfRenderWindow_setMouseCursorVisible(win->win, sfTrue);
}

void	next_game_draw(win_t *win, scene_t *scene)
{
	win->heros.real_pos = (sfVector2f){(win->heros.pos.x -
	scene[win->scene].map->tr.x), (win->heros.pos.y -
	scene[win->scene].map->tr.y)};
	entity_t *entity = create_entity(win->heros.real_pos,
	SPRITE, win->heros.spt, 1);
	add_entity(entity, scene[win->scene].entity_manager[
	((int)(entity->real_pos.y) / 40)]);
	manage_entity(win, &scene[win->scene]);
	my_draw_window(win->win, scene[win->scene].map, win,
	scene[win->scene]);
	manage_entity_after(win, &scene[win->scene]);
	remove_entity(entity, scene[win->scene].entity_manager[
	((int)(entity->real_pos.y) / 40)]);
	kill_entity(entity, NULL);
	move_npc(win, scene[win->scene], scene[win->scene].npc);
	validate_quests(win, scene);
	quest_book(win);
	print_ai(win, scene[win->scene].monster);
	transition_act_one(win, &scene[win->scene]);
}

void	next_next_prev_game(win_t *win, scene_t *scene)
{
	display_inventory(win);
	display_hp_bar(win);
	npc_speak(scene[win->scene].npc, win);
	particles_manager(&scene[win->scene], win);
	draw_spell(win, win->spell);
	parcour_entity(win, scene[win->scene]);
	switch_ater_cine(win, scene);
	check_spell_damage(win, scene[win->scene].monster, win->spell);
	draw_particles(scene[win->scene].particle_manager->root_c, win->win);
}

void	next_game(win_t *win, scene_t *scene)
{
	level_up(win, scene);
	answer_save_point(scene, win);
	map_events(win, scene);
	if (win->state == 0) {
		move_ia(win, scene[win->scene].monster, scene[win->scene].map);
		timer_move(win, scene);
	}
	sfSprite_setTextureRect(win->heros.spt, win->heros.rect);
	next_game_draw(win, scene);
	next_next_prev_game(win, scene);
	check_pause_draw(win);
	settings(win);
	if (win->heros.stat.stat_end[0] <= 0)
		hero_death(win, scene);
	sfRenderWindow_display(win->win);
}

void	game(win_t *win, scene_t *scene)
{
	sfRenderWindow_clear(win->win, sfBlack);
	while (sfRenderWindow_pollEvent(win->win, &win->evt)) {
		if (win->evt.type == sfEvtClosed)
			sfRenderWindow_close(win->win);
		if (win->evt.type == sfEvtKeyReleased) {
			if (win->evt.key.code == sfKeyM)
				switch_scene(win, scene, 90);
			if (win->evt.key.code ==
			sfKeyReturn && win->num_cine != 0)
				skip_cine(win, &scene[win->scene]);
		}
		npc_events(win, scene[win->scene].npc);
		book_events(win);
		different_state(win, scene);
	}
	if (win->state == -42) {
		load(scene, win);
		win->state = 0;
	}
	next_game(win, scene);
}
