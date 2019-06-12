/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MYNPC_H_
#define MYNPC_H_

#include "struct.h"

// npc
void	new_npc(npc_t **, char *, win_t *);
void	npc_active(npc_t *, int, win_t *);
void	npc_speak(npc_t *, win_t *);
void	new_npc_dial(npc_t *);
void	init_cursor(npc_t *);
npc_t	*find_active_npc(npc_t *);
void	move_cursor_left(npc_t *);
void	move_cursor_right(npc_t *);
void	valid_answer(npc_t *, win_t *);
void	blink_cursor(ans_curs_t);
void	restart_npc(npc_t *);
void	go_to_next_sentence(npc_t *, win_t *);
void	carriage_return(int, sfText *, npc_t *);
void	scroll_text(int, sfText *, npc_t *);
void	decrease_text_speed(npc_t *);
void	increase_text_speed(npc_t *);
void	create_new_dialogue(npc_t *, char *, int);
void	new_already_node(tree_t **);
void	new_npc_spr(npc_t *, char **, win_t *);
void	interact_npc(win_t *, npc_t *);
void	draw_behind_npc(win_t *, npc_t *);
void	draw_front_npc(win_t *, npc_t *);
void	rotate_npc(npc_t *, win_t *);
void	move_npc_on_map(npc_t *, sfVector2f);
npc_t	*find_npc(npc_t *, int);
void	move_dial_ptr(npc_t *, win_t *);
void	free_quest_node(tree_t **);
void	move_npc_here_left(npc_t *, int, win_t *);
void	move_npc_here_right(npc_t *, int, win_t *);
void	move_npc_here_up(npc_t *, int, win_t *);
void	move_npc_here_down(npc_t *, int, win_t *);
void	new_npc_move(npc_t *);
void	move_npc(win_t *, scene_t, npc_t *);
int	npc_collision(npc_t *, win_t *, sfVector2f);
void	restart_str_ptr(npc_t *);
void	free_all_npc(npc_t *);
void	free_npc(npc_t *);
void	display_npc_pict(npc_t *, win_t *);
void	switch_new_node(npc_t *, char *, int);
int	interact_front_npc(npc_t *, win_t *);
void	show_sell_price(npc_t *, win_t *);
void	print_item_price_sell(npc_t *, obj_t, win_t *);
void	arrow_animations(win_t *, npc_t *);
void	arrow_click_merch(win_t *, npc_t *);

// merchant
void	new_npc_merchant(npc_t *, win_t *, char **);
void	merchant(npc_t *, win_t *);
void	display_merch(npc_t *, win_t *);
void	init_merch_items(npc_t *, win_t *, char **);
void	close_merch(npc_t *, win_t *);
void	select_item_merch(npc_t *, win_t *);
void	move_selection_merch(npc_t *, win_t *);
void	buy_item(npc_t *, win_t *);
void	buy_merch_selection(npc_t *, win_t *);
void	restore_invent_merch(win_t *);
void	reset_pos_text_invent_merch(win_t *);
void	display_merch_arrow(npc_t *, win_t *);
void	go_right_merch(npc_t *, win_t *);
void	go_left_merch(npc_t *, win_t *);
void	click_left_arrow(npc_t *, win_t *);
void	click_right_arrow(npc_t *, win_t *);
int	has_more_item(npc_t *, win_t *);
void	display_inventory_merch(win_t *);
void	merch_inventory_handling(win_t *);
void	merch_give_item(merch_item_t *, win_t *);
void	restart_merchant(npc_t *, win_t *);
void	click_sell_item(npc_t *, win_t *);
void	release_sell_item(npc_t *, win_t *);
void	merch_mouse_pressed(win_t *, npc_t *);
void	merch_sell_item(npc_t *, win_t *);
void	init_sell_merchant(npc_t *, win_t *);
void	right_click_sell_item(npc_t *, win_t *);

// parse dial file
int	my_get_index(char *);
char	*get_single_str(char *, int *, int);
void	new_left_node(tree_t **);
void	new_mid_node(tree_t **);
void	new_right_node(tree_t **);
void	fill_bin_tree(npc_t *, int);
void	get_prop_str(tree_t *, int *, char *);
void	cut_text(npc_t *);

//quests
void	valid_quest_one(win_t *, quest_t *, scene_t *);
void	valid_quest_two(win_t *, quest_t *, scene_t *);
void	valid_quest_three(win_t *, quest_t *, scene_t *);
void	valid_quest_four(win_t *, quest_t *, scene_t *);
void	valid_quest_five(win_t *, quest_t *, scene_t *);
void	new_quest(win_t *, int);
void	init_quests(win_t *);
int	get_quest_nb(char *, int);
quest_t	*find_quest(quest_t *, int);
void	change_quest_state(char *, int, win_t *, int);
void	new_quest_node(tree_t **);
void	validate_quests(win_t *, scene_t *);
void	draw_quests(win_t *);
void	init_quest_rect(quest_t *);
void	move_quest_rect_right(quest_t *);
void	move_quest_rect_left(quest_t *);
void	init_quest_fct(quest_t *, int);
void	init_quest_book(win_t *);
void	display_quest_book(win_t *);
void	quest_book(win_t *);
void	remove_all_quest_node_in_scene(scene_t *, int);
void	remove_all_quest_node(npc_t *, int);
void	init_book_switch(win_t *);
void	attrib_rewards_quest_two(win_t *);
void	attrib_rewards_quest_one(win_t *);
void	attrib_rewards_quest_three(win_t *);
void	attrib_rewards_quest_four(win_t *);
void	attrib_rewards_quest_five(win_t *);
void	book_events(win_t *);
void	enable_tp(scene_t *, quest_t *);

// save_point
void	new_save_point(npc_t *, win_t *, char **);
void	answer_save_point(scene_t *, win_t *);

#endif
