/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include "include.h"
#include "macro.h"
#include "struct.h"
#include "get_next_line.h"
#include "map.h"
#include "particle.h"
#include "mynpc.h"
#include "entities.h"

//basic
void	game(win_t *, scene_t *);
void	reset_game(win_t *win, scene_t **scene);
void	init_window(win_t *win);
void	init_heros(win_t *win);
void	init_heros_stat(win_t *win);
scene_t	*create_scene(int nb);
void	menu(win_t *, scene_t **);
char	*my_strcat(char *s1, char *s2);
void	different_state(win_t *win, scene_t *scene);
void	check_pause_draw(win_t *win);

//Object
obj_t *create_object(const char *, inits_t, int, object_t);
inits_t	inits_pos_rect(inits_t *, sfVector2f, sfIntRect,
sfVector2f scale);

// Event
void	heros_event_handle(win_t *);

//inventory
void	init_inventory(win_t *win);
void	init_item(win_t *win);
void	init_struct_mouse(mouse_t *mouse);
void	init_parseur_base(obj_t *item, char *str, int nb);
void	init_parseur_stat(obj_t *item, char *str, int nb);
void	init_inventory_text(win_t *win);
void	init_char_stat_item(obj_t *item, int c);
void	init_background(win_t *win);
void	text_init(text_t *text, char *str, sfVector2f pos, int size);
void	analyse_events(win_t *);
void	drag_and_drop_inv(win_t *win, sfVector2i pos);
void	mouse_pose(win_t *win, sfVector2i pos);
void	display_stat_item(win_t *win, int c);
void	display_inventory(win_t *win);
void	display_stat(win_t *win);
void	display_mouse_dad(win_t *win);
void	draw_back_of_stat(win_t * win, int c, int pos);
void	draw_stat_item_right(win_t *win, int nb, int c, sfVector2f pos);
void	draw_stat_item_left(win_t *win, int nb, int c, sfVector2f pos);
void	draw_type_stat(win_t *win, sfVector2f pos, int *nb, int posi);
char	*my_getstr(int nb);
char	**my_str_to_word_array_inv(char *str);
void	display_stat_of_heros(win_t *win);
void	change_stat_item_heros(win_t *win);
void	init_struct_display_stat_heros(win_t *win);
void	display_hp_bar(win_t *win);
void	domage_heros(win_t *win);
void	win_give_item(win_t *win, int c);
void	init_pict_stat(obj_t *pict);
void	display_pict_stat(win_t *win);
void	display_loot(purse_t *liste, win_t *win);
void	move_bourse_on_map(purse_t *liste, sfVector2f offset);
void	envent_loot(win_t *win);
void	init_liste_item(win_t *win);
void	event_loot(win_t *win);
void	display_loot_page(win_t *win);
void	display_item(win_t *win);
void	display_mouse_case(win_t *win, int c);
void	change_ver_mouse(win_t *win);
void	take_item_loot(win_t *win);
void	insertion_loot(win_t *win, int map, sfVector2f pos, int *item);
void	delet_item_loot(purse_t *actual);
void	delet_purse_loot(win_t *win);
void	loot_button(purse_t *tmp, win_t *win);
int	*gene_item(win_t *win);
void	classement_inv(win_t *win);
void	init_hp_bar(win_t *win, rect_shape_t *rect);

// utils
int	my_strlen(char *);
char	*my_strdup(char *);
char	*my_straddch(char *, char);
int	my_strcmp(char *, char *);

// events
void	npc_key_released(win_t *, npc_t *);
void	npc_events(win_t *, npc_t *);

//heros
void	move_rect_attack(obj_t *heros, int offset);
void	player_attack(obj_t *heros);
void	move_player(obj_t *heros);
void	anim_player(obj_t *heros);
void	init_background_inv(rect_shape_t *rect, sfVector2f size,
	sfIntRect color);
void	choose_hitbox(win_t *win, monster_t *monster, int save);
void	move_heros(win_t *win, map_t *map, npc_t *npc, monster_t *monster);
void	hero_death(win_t *win, scene_t *scene);
win_anim_t create_hero_death_struct(win_t *win);
sfText	*create_dead_text(win_t *win);
void	destroy_hero_death_struc(win_anim_t *info);
void	reset_player_move(win_t *win);

//map
char	**my_str_to_word_array(char *, char);
int	my_getnbr(char *);

//menu
void	create_menu(win_t *win);
void	move_menu(menu_t *menu, win_t *win);
void	play_button(win_t *win, scene_t *scene);
void	exit_button(win_t *win, scene_t *scene);
void	set_alpha_text(win_t *win);
void	event_pause(win_t *win, scene_t *scene);
void	display_cursor(win_t *win);
void	draw_menu_pause(win_t *win);
void	settings_button(win_t *win, scene_t *scene);
void	settings(win_t *win);
void	up_music(win_t *win, scene_t *scene);
void	blink_cursor_menu(obj_t *cursor);
void	less_music(win_t *win, scene_t *scene);
void	test_settings_event(win_t *win, scene_t *scene);
void	check_button_pause(menu_t *menu, sfMouseMoveEvent evt, int i);
void	check_click_pause(win_t *win, sfMouseButtonEvent evt, int i, scene_t
*scene);
void	credit(win_t *win, scene_t *scene);
void	change_color_set_click(win_t *win, int nb);
void	init_button_menu(win_t *win);
void	change_pos_button(win_t *win);
void	back_to_the_menu(win_t *win, scene_t *scene);
void	continue_the_game(win_t *win, scene_t *scene);
void	replace_settings_menu(win_t *win);
void	draw_credits(win_t *win);
void	luminosity_less(win_t *win, scene_t *s);
void	luminosity_add(win_t *win, scene_t *s);
void	settings_init(win_t *win);

//path fiding
int	path_finding(map_t *map, win_t *win, obj_t *monster, monster_t
*list_m);
void	add_openlist(start_t *list, int x, int y);
void	add_closelist(start_t *list, int x, int y);
void	remove_closelist(start_t *list);
void	remove_openlist(start_t *list, int *data);
start_t	*inits_list(win_t *win, map_t *map, obj_t *monster);
int	is_in_list(list_t *open_list, list_t
*closed_list, int x, int y);
void	fill_case_down(node_t **grid, start_t *list,
sfVector2i x, int *pos);
int	is_in_list(list_t *open_list, list_t *closed_list, int x, int y);
void	fill_case(node_t **grid, start_t *list, sfVector2i x, int *pos);
void	fill_info(start_t *list, node_t **grid, int *pos, map_t *map);
void	fill(node_t **grid, int *origin, map_t *map, monster_t *list_m);
void	find_min(list_t *list, node_t **grid, int *pos);
void	set_particle_on_monster(monster_t *monster, scene_t *scene,
	win_t *win);

//ia
monster_t	*create_ia_list(monster_t *monster, char *name, int x, int y);
obj_t	*create_ia(char *name, int x, int y);
char	*clean_str(char *str);
void	move_ia_cam(monster_t *monster, sfVector2f offset);
void	move_ia(win_t *win,  monster_t *monster, map_t *map);
void	print_ai(win_t *win, monster_t *monster);
void	parse_monster(char *s, scene_t *scenes, win_t *win);
void	init_print_damage(monster_t *monster, win_t *win);
void	move_rect_ia(monster_t *tmp, int offset);
void	anim_ia(monster_t *tmp);
void	change_print_bar(monster_t *tmp, win_t *win);
void	change_damage(monster_t *tmp, win_t *win, int damage);
void	heros_take_damage(monster_t *tmp, win_t *win);
void	print_damage(monster_t *tmp, win_t *win);
void	ia_attack(win_t *win, monster_t *monster);
sfText	*create_text(char *str, sfVector2f pos, win_t *win);
void	add_xp(win_t *win, monster_t *tmp);
void	level_up(win_t *win, scene_t *scene);
void	anim_ia_attack(monster_t *tmp);
int	move_ia_y(monster_t *tmp);
int	move_ia_x(monster_t *tmp);
void	check_ia(win_t *win,
monster_t *tmp, map_t *map, monster_t *monster);
void	fill_posm(monster_t *list_m, node_t **grid, map_t *map);
void	free_grid(start_t *list, node_t **grid, map_t *map);
void	free_path(list_t *list);

//player
void	hitbox_right(win_t *win, monster_t *tmp);
void	hitbox_left(win_t *win, monster_t *tmp);
void	hitbox_down(win_t *win, monster_t *tmp);
void	hitbox_up(win_t *win, monster_t *tmp);
void	draw_spell(win_t *win, obj_t *spell);
void	check_spell_damage(win_t *win, monster_t *monster,  obj_t *spell);
void	idle_anim(win_t *win, int stop);
int	end_move(win_t *win, int i, int *stop, sfIntRect origin);
void	timer(obj_t *heros, int save, win_t *win, int stop);
void	choose_direc(win_t
*win, map_t *map, npc_t *npc, monster_t *monster);
void	change_xp_bar(win_t *win);
void	timer_move(win_t *win, scene_t *scene);

//cinematique
void	get_cmd(win_t *win, scene_t scene);
int	my_getnbr_neg(char *str);
int	my_tab_len(char **str);
void	get_entity_npc(win_t *win, scene_t scene, char **cmd,
cine_t *element);
void	move_n_npc(win_t *win, scene_t scene, int move, int num_npc);
int	move_entity_c(win_t *win, scene_t scene, cine_t *tmp);
void	parcour_entity(win_t *win, scene_t scene);
void	free_cine(win_t *win);
void	get_entity_play(win_t *win, scene_t scene, char **cmd, cine_t
*element);
int	stop_heros(win_t *win, scene_t scene, cine_t *tmp);
void	get_cine_num(win_t *win, scene_t scene, int num);
int	slow_dialogue(win_t *win, scene_t scene, cine_t *tmp);
void	get_entity_dial(win_t *win, scene_t scene, char **cmd,cine_t
*element);
cine_t	*new_list(void);
void	add_list(win_t *win, scene_t scene, char **cmd, int i);
void	reset_value(win_t *win);
int	skip_entity(win_t *win, scene_t *scene, cine_t *tmp);
void	skip_cine(win_t *win, scene_t *scene);
int	cmd_atk(int *stop, sfIntRect ori, win_t *win, monster_t *monster);
void	move_up(win_t *win, map_t *map, npc_t *npc, monster_t *monster);
void	move_right(win_t *win, map_t *map, npc_t *npc, monster_t *monster);
void	move_left(win_t *win, map_t *map, npc_t *npc, monster_t *monster);
void	move_down(win_t *win, map_t *map, npc_t *npc, monster_t *monster);
void	place_pnj_act_one(win_t *win, scene_t *scene);
int	next_act(menu_t *menu, win_t *win, scene_t *scene, int num);
void	place_pnj_act_two(win_t *win, scene_t *scene);
void	go_to_next_line(int *state, char **str, int fd, char *str2);
void	check_boss_death(win_t *win, monster_t *tmp);
void	transition_act_one(win_t *win, scene_t *scene);
void	switch_ater_cine(win_t *win, scene_t *scene);

// consumable
void	consumable_events(win_t *);

//music
void	init_music_menu(win_t *win);
void	play_music(win_t *win, int nb, int stop);
void	play_sound(win_t *win, int nb);
void	free_music(win_t *win);

//scenes
scene_t	*init_scenes(char *filename, int nb, win_t *win);
void	init_targeted_scenes(char *filename, int nb, win_t *win, scene_t
*scene);
void	destroy_scenes(scene_t *scenes, int nb);
void	print_loading_screen(win_t *win, int nb);

// save load
int	save(scene_t *, win_t *);
int	load(scene_t *, win_t *);
void	skip_dialogues(npc_t *, quest_t *);
void	load_monsters(scene_t *, win_t *, int, int);
void	load_npc(scene_t *, win_t *, int, int);
void	load_scene(scene_t *, win_t *, int, int);

//color
void	decrease_red_color(sfColor *color, int offset,
	sfBool alpha, int offset_alpha);

int	secure_config(void);

#endif
