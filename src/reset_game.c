/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg
*/

#include "my.h"

void	reset_game(win_t *win, scene_t **scene)
{
	win->state = 0;
	win->cine = new_list();
	init_heros(win);
	init_heros_stat(win);
	init_inventory(win);
	init_quests(win);
	*scene = create_scene(NB_SCENE);
	set_tp_disable(*scene);
	init_targeted_scenes("other/scene", win->scene, win, *scene);
	win->ver[3] = 0;
	change_pos_button(win);
	play_music(win, 0, win->num_music);
	sfRenderWindow_setMouseCursorVisible(win->win, sfFalse);
	get_cine_num(win, (*scene)[win->scene], 1);
}
