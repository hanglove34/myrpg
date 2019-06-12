/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	npc_key_released(win_t *win, npc_t *npc)
{
	switch (win->evt.key.code) {
		case (sfKeyLeft):
			move_cursor_left(npc);
			break;
		case (sfKeyRight):
			move_cursor_right(npc);
			break;
		case (sfKeyReturn):
			interact_npc(win, npc);
			if (win->num_cine == 0)
				go_to_next_sentence(npc, win);
			valid_answer(npc, win);
			decrease_text_speed(npc);
			break;
	}
}

void	npc_key_pressed(win_t *win, npc_t *npc)
{
	switch (win->evt.key.code) {
		case (sfKeyReturn):
			increase_text_speed(npc);
			break;
		case (sfKeyL):
			play_sound(win, 3);
			win->quest_book.state[0] *= -1;
			change_ver_mouse(win);
			display_cursor(win);
			break;
	}
}

void	merch_mouse_released(win_t *win, npc_t *npc)
{
	if (win->evt.mouseButton.button == sfMouseLeft) {
		close_merch(npc, win);
		select_item_merch(npc, win);
		buy_item(npc, win);
		click_left_arrow(npc, win);
		click_right_arrow(npc, win);
		release_sell_item(npc, win);
	} else if (win->evt.mouseButton.button == sfMouseRight) {
		right_click_sell_item(npc, win);
	}
}

void	merch_mouse_moved(win_t *win, npc_t *npc)
{
	move_selection_merch(npc, win);
	buy_merch_selection(npc, win);
}

void	npc_events(win_t *win, npc_t *npc)
{
	switch (win->evt.type) {
		case (sfEvtKeyReleased):
			npc_key_released(win, npc);
			break;
		case (sfEvtKeyPressed):
			npc_key_pressed(win, npc);
			break;
		case (sfEvtMouseButtonReleased):
			merch_mouse_released(win, npc);
			break;
		case (sfEvtMouseMoved):
			merch_mouse_moved(win, npc);
			break;
		case (sfEvtMouseButtonPressed):
			merch_mouse_pressed(win, npc);
			break;
	}
}
