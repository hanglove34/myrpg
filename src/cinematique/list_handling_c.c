/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	add_list(win_t *win, scene_t scene, char **cmd, int i)
{
	cine_t *element = malloc(sizeof(*element));
	element->next = win->cine;
	win->cine->prev = element;
	element->prev = NULL;
	switch (i) {
		case 1:
			get_entity_npc(win, scene, cmd, element);
			break;
		case 2:
			get_entity_play(win, scene, cmd, element);
			break;
		case 3:
			get_entity_dial(win, scene, cmd, element);
			break;
	}
	win->cine = element;
}

void	free_and_place(win_t *win, cine_t *p_del)
{
	if (p_del->prev == NULL) {
		win->cine = win->cine->next;
		win->cine->prev = NULL;
	} else {
		p_del->next->prev = p_del->prev;
		p_del->prev->next = p_del->next;
	}

}

void	free_cine(win_t *win)
{
	cine_t *p_temp = win->cine;
	while (p_temp != NULL && p_temp->next != NULL) {
		cine_t *p_del = p_temp;
		if (p_del->num != -1) {
			if (p_del->next == NULL)
				win->cine->prev->next = NULL;
			else
				free_and_place(win, p_del);
			free(p_del);
			while (win->cine->next == NULL)
				return;
		}
		p_temp = p_temp->next;
	}
}

cine_t	*new_list(void)
{
	cine_t *element = malloc(sizeof(*element));
	element->next = NULL;
	element->prev = NULL;
	element->num = -1;
	element->origin = 0;
	element->pos = 0;
	return (element);
}
