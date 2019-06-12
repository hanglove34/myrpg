/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

sfVector2f	get_pos(char *s)
{
	sfVector2f pos;
	char **value = NULL;

	value = my_str_to_word_array(s, ' ');
	pos = (sfVector2f){my_getnbr_neg(value[0]), my_getnbr_neg(value[1])};
	free(value);
	return (pos);
}

char	*get_map(char *s, int fd, scene_t *scenes, win_t *win)
{
	sfVector2f pos;
	sfVector2f tr;

	if (my_strcmp(s, "<map") != 0)
		return NULL;
	while (s[0] != '>') {
		s = clean_str(get_next_line(fd));
		tr = get_pos(s);
		s = clean_str(get_next_line(fd));
		pos = get_pos(s);
		s = clean_str(get_next_line(fd));
		scenes->map = my_create_map(s, win, (pos_map_t){pos, tr});
		s = clean_str(get_next_line(fd));
	}
}

char	*get_npc(char *s, int fd, scene_t *scenes, win_t *win)
{
	scenes->npc = NULL;
	s = clean_str(get_next_line(fd));
	while (s && s[0] != '>') {
		new_npc(&scenes->npc, s, win);
		free(s);
		s = clean_str(get_next_line(fd));
	}
	return (s);
}

char	*get_monster(char *s, int fd, scene_t *scenes, win_t *win)
{
	monster_t *new = malloc(sizeof(*new));
	new->next = NULL;
	new->monster = NULL;
	scenes->monster = new;
	while (s[0] != '>') {
		s = clean_str(get_next_line(fd));
		parse_monster(s, scenes, win);
	}
	init_print_damage(scenes->monster, win);
	return (s);
}
