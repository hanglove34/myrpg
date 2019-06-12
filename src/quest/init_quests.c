/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	init_quests(win_t *win)
{
	win->quest = NULL;
	new_quest(win, 1);
	new_quest(win, 2);
	new_quest(win, 3);
	new_quest(win, 4);
	new_quest(win, 5);
	init_quest_book(win);
}

char	*get_quest_str(char *s)
{
	int i = 0;
	int j = 0;
	char *str = malloc(sizeof(char) * (my_strlen(s) + 1));

	while (s && s[i] && s[i] != 34)
		i += 1;
	i += 1;
	while (s && s[i] && s[i] != 34) {
		str[j] = s[i];
		if (s[i] == '$')
			str[j] = '\n';
		j += 1;
		i += 1;
	}
	str[j] = '\0';
	return (str);
}

void	init_quest_text(quest_t *new, unsigned int size, sfVector2f pos)
{
	new->state = 0;
	new->text.txt = sfText_create();
	new->text.size = size;
	new->text.font = sfFont_createFromFile("img/font.ttf");
	new->text.pos = pos;
	sfText_setFont(new->text.txt, new->text.font);
	sfText_setCharacterSize(new->text.txt, size);
	sfText_setPosition(new->text.txt, pos);
	sfText_setColor(new->text.txt, sfWhite);
	sfText_setString(new->text.txt, new->text.str);
}

void	put_new_quest(quest_t *new, win_t *win, int nb)
{
	quest_t *tmp = win->quest;

	new->nb = nb;
	init_quest_fct(new, nb);
	init_quest_text(new, 25, (sfVector2f){-200, 150});
	init_quest_rect(new);
	while (tmp && tmp->next)
		tmp = tmp->next;
	new->next = NULL;
	new->prev = tmp;
	if (tmp)
		tmp->next = new;
	else
		win->quest = new;
}

void	new_quest(win_t *win, int nb)
{
	int fd = open("other/quest", O_RDONLY);
	char *s = get_next_line(fd);
	quest_t *new = malloc(sizeof(*new));

	while (s) {
		if (s[0] == '<' && my_get_index(s) == nb)
			break;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	s = get_next_line(fd);
	new->text.str = get_quest_str(s);
	free(s);
	s = get_next_line(fd);
	new->longer_str = get_quest_str(s);
	free(s);
	put_new_quest(new, win, nb);
}
