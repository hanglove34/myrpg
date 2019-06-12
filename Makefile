##
## EPITECH PROJECT, 2017
## mf
## File description:
## mf
##

SRC	=	src/main.c						\
		src/menu.c						\
		src/obj_create.c					\
		src/game.c						\
		src/my_getnbr_neg.c					\
		src/secure_config.c					\
		src/player/hero_event.c					\
		src/player/spell.c					\
		src/player/spell_damage.c				\
		src/player/heros_anim.c					\
		src/player/heros_anim_attack.c				\
		src/cinematique/skip_cine.c				\
		src/cinematique/move_npc_c.c				\
		src/cinematique/move_player_c.c				\
		src/cinematique/list_handling_c.c			\
		src/cinematique/make_cine.c				\
		src/cinematique/dialogue_npc_c.c			\
		src/cinematique/cinematic.c				\
		src/player/heros_atk.c					\
		src/player/hero_action.c				\
		src/player/hero_move.c					\
		src/player/hitbox.c					\
		src/boss/select_anim_end.c				\
		src/boss/act_one.c					\
		src/utils.c						\
		src/randomize_loot.c					\
		src/player/xp_manage.c					\
		src/get_next_line.c					\
		src/menu/anim_menu.c					\
		src/menu/main_menu_init.c				\
		src/menu/pause_menu.c					\
		src/menu/button_menu_main.c				\
		src/path_finding/damage_handle.c			\
		src/path_finding/chained_list_path.c			\
		src/path_finding/path_finding.c				\
		src/path_finding/create_ia.c				\
		src/path_finding/anim_ia.c				\
		src/path_finding/case_manage.c				\
		src/path_finding/print_damage.c				\
		src/music/music_create.c				\
		src/path_finding/main_ia.c				\
		src/clean_str.c						\
		src/menu/settings_display.c				\
		src/menu/settings_event.c				\
		src/menu/button_action_pointeur.c			\
		src/menu_settings.c					\
		src/my_strncmp.c					\
		src/menu/button_menu_init.c				\
		src/menu/change_pos_settings.c				\
		src/menu/luminosity_change.c				\
		src/player/hero_death.c					\
		src/color/update_color.c				\
		src/path_finding/set_particle_monster.c			\
		src/player/hero_death_struct.c				\
		src/other_event.c					\
		src/reset_game.c					\
		src/reset_player_move.c					\
		$(NPC)							\
		$(MAP)							\
		$(INV)							\
		$(QUEST)						\
		$(SCENE)						\
		$(PARTICLE)						\
		$(ENTITIES)						\
		$(SAVE)

NPC	=	src/npc/display/npc_dialogue.c				\
		src/npc/init/init_npc.c					\
		src/npc/init/init_bin_tree.c				\
		src/npc/init/init_binary_tree.c				\
		src/npc/other/restart_npc.c				\
		src/npc/other/parse_dial_file.c				\
		src/npc/other/select_answer.c				\
		src/npc/other/npc_events.c				\
		src/npc/other/npc_navigate.c				\
		src/npc/other/npc_organize_text.c			\
		src/npc/other/npc_speed_text.c				\
		src/npc/init/init_dialogues.c				\
		src/npc/init/init_npc_spr.c				\
		src/npc/display/draw_npc.c				\
		src/npc/display/move_npc.c				\
		src/npc/other/free_dial.c				\
		src/npc/init/init_npc_move.c				\
		src/npc/display/npc_collision.c				\
		src/npc/other/npc_events_more.c				\
		src/npc/other/free_npc.c				\
		src/npc/display/npc_pict.c				\
		$(MERCHANT)

QUEST	=	src/quest/init_quests.c					\
		src/quest/valid_quest.c					\
		src/quest/valid_more_quest.c					\
		src/quest/quests.c					\
		src/quest/draw_quests.c					\
		src/quest/init_quest_rect.c				\
		src/quest/init_quest_book.c				\
		src/quest/quest_book.c					\
		src/quest/book_rewards.c				\
		src/quest/switch_page.c

MERCHANT=	src/npc/merchant/init/init_npc_merchant.c		\
		src/npc/merchant/init/init_merch_item.c			\
		src/npc/merchant/display/merchant.c			\
		src/npc/merchant/display/display_merch.c		\
		src/npc/merchant/display/merchant_events.c		\
		src/npc/merchant/display/merchant_inventory.c		\
		src/npc/merchant/display/merchant_arrows.c		\
		src/npc/merchant/display/merch_items.c			\
		src/npc/merchant/display/sell_items.c			\
		src/npc/merchant/init/init_sell_merchant.c		\
		src/npc/merchant/display/merch_anim.c

MAP	=	src/map/my_draw.c					\
		src/map/my_map.c					\
		src/map/create_obj.c					\
		src/map/my_str_to_word_array.c				\
		src/map/my_getnbr.c					\
		src/map/map_colision.c					\
		src/map/init_all_tileset_and_launch_map_config.c	\
		src/map/map_move.c					\
		src/map/map_event.c					\
		src/map/test_event.c					\
		src/map/get_maps.c					\
		src/map/index_management.c				\
		src/map/get_tex.c					\
		src/map/get_tilesets.c					\
		src/map/my_str_to_word_array_static.c			\
		src/map/destroy_map.c					\
		src/map/switch_scene_town.c				\
		src/map/switch_scene_castle.c				\
		src/scene/init_content.c				\
		src/map/draw_objects.c					\
		src/map/switch_act_two_part_one.c			\
		src/map/switch_scene_act_one.c				\

INV	=	src/inventory/display/display_inventory.c		\
		src/inventory/event/event_inventory.c			\
		src/inventory/init/init_inventory.c			\
		src/inventory/init/init_item.c				\
		src/inventory/init/init_mouse.c				\
		src/inventory/event/drag_and_drop_inventory.c		\
		src/inventory/display/display_mouse_inv.c		\
		src/inventory/event/drag_and_drop_inventory_suit.c	\
		src/inventory/init/init_inventory_text.c		\
		src/inventory/init/parseur_item.c			\
		src/inventory/display/display_stat_item.c		\
		src/inventory/init/init_char_stat_item.c		\
		src/inventory/init/init_back.c				\
		src/inventory/init/init_hp_bar.c			\
		src/inventory/my_getstr.c				\
		src/inventory/display/display_stat_item_suit.c		\
		src/inventory/display/display_stat_of_heros.c		\
		src/inventory/event/change_stat.c			\
		src/inventory/display/display_hp_bar.c			\
		src/inventory/event/add_item_inventory.c		\
		src/inventory/init/init_pict_stat.c			\
		src/inventory/display/display_pict_stat.c		\
		src/inventory/event/insertion.c				\
		src/inventory/display/display_bourse_map.c		\
		src/inventory/event/event_loot.c			\
		src/inventory/display/display_loot_page.c		\
		src/inventory/event/take_item_loot.c			\
		src/inventory/event/delet_item_loot.c			\
		$(CONS)

CONS	=	src/inventory/event/consumable_events.c

SCENE	=	src/scene/init_scene.c					\
		src/scene/destroy_scenes.c				\
		src/scene/loading_screen.c				\
		src/scene/set_tp_disable.c				\

PARTICLE =	src/particle/particle.c					\
		src/particle/contener_tools.c				\
		src/particle/init_particle_tools.c			\
		src/particle/light_particle.c				\
		src/particle/light_particles_contener.c			\
		src/particle/dead_particle.c				\
		src/particle/dead_particles_contener.c			\

ENTITIES =	src/entities/entity.c					\
		src/entities/manage_entity.c				\
		src/entities/create_entity.c				\

SAVE	=	src/save/save.c						\
		src/save/load.c						\
		src/save/save_point.c					\
		src/save/load_dialogues.c				\
		src/save/load_scene.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -I ./include -lm

NAME	=	my_rpg

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lc_graph_prog $(CFLAGS)

play:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f my_rpg

re:	fclean all

replay: fclean play
