/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	add_openlist(start_t *list, int x, int y)
{
	list_t *element = malloc(sizeof(*element));
	element->next = list->open_list;
	list->open_list->prev = element;
	element->prev = NULL;
	element->x = x;
	element->y = y;
	list->open_list = element;
}

void	add_closelist(start_t *list, int x, int y)
{
	list_t *element = malloc(sizeof(*element));
	element->next = list->closed_list;
	list->closed_list->prev = element;
	element->prev = NULL;
	element->x = x;
	element->y = y;
	list->closed_list = element;
}

void	remove_closelist(start_t *list)
{
	list_t *element = list->closed_list;
	while (element != NULL && list->closed_list != NULL) {
		if (element->next == NULL)
			list->closed_list->prev->next = NULL;
		else if (element->prev == NULL) {
			list->closed_list = list->closed_list->next;
			list->closed_list->prev = NULL;
		} else {
			element->next->prev = element->prev;
			element->prev->next = element->next;
		}
		free(element);
		break;
		element = element->next;
	}
}

void	remove_openlist(start_t *list, int *data)
{
	list_t *element = list->open_list;
	while (element->next != NULL && list->open_list != NULL) {
		if (data[0] == element->x && data[1] == element->y) {
			if (element->next == NULL)
				list->open_list->prev->next = NULL;
			else if (element->prev == NULL) {
				list->open_list = list->open_list->next;
				list->open_list->prev = NULL;
			} else {
				element->next->prev = element->prev;
				element->prev->next = element->next;
			}
			free(element);
			break;
		}
		element = element->next;
	}
}

start_t	*inits_list(win_t *win, map_t *map, obj_t *monster)
{
	start_t *new = malloc(sizeof(*new));
	list_t *element1 = malloc(sizeof(*element1));
	element1->next = NULL;
	element1->prev = NULL;
	element1->x = -1;
	element1->y = -1;
	list_t *element2 = malloc(sizeof(*element2));
	element2->next = NULL;
	element2->prev = NULL;
	element2->x = -1;
	element2->y = -1;
	new->open_list = element1;
	new->closed_list = element2;
	new->end[0] = (monster->pos.x - map->tr.x) / SCALE_MAP;
	new->end[1] = ((monster->pos.y - map->tr.y) / SCALE_MAP);
	new->start[0] = (win->heros.pos.x - map->tr.x) / SCALE_MAP;
	new->start[1] = (win->heros.pos.y - map->tr.y) / SCALE_MAP;
	return (new);
}
