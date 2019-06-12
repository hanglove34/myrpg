/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

void	init_cursor(npc_t *new)
{
	new->cursor.tex = sfTexture_createFromFile("img/cursor.png", NULL);
	new->cursor.spr = sfSprite_create();
	sfSprite_setTexture(new->cursor.spr, new->cursor.tex, sfTrue);
	new->cursor.pos = malloc(sizeof(*(new->cursor.pos)) * 3);
	new->cursor.pos[0].x = new->text_pos[1].x - 75;
	new->cursor.pos[0].y = new->text_pos[1].y + 5;
	new->cursor.pos[1].x = new->text_pos[2].x - 75;
	new->cursor.pos[1].y = new->text_pos[2].y + 5;
	new->cursor.pos[2].x = new->text_pos[3].x - 75;
	new->cursor.pos[2].y = new->text_pos[3].y + 5;
	new->cursor.state = 0;
	new->cursor.answer = 1;
	new->cursor.fptr = &blink_cursor;
	new->cursor.blink.clock = sfClock_create();
	sfSprite_setScale(new->cursor.spr, (sfVector2f){4, 4});
	sfSprite_setPosition(new->cursor.spr, new->cursor.pos[0]);
}

void	new_npc_text(npc_t *new)
{
	int i = 0;
	new->font = sfFont_createFromFile("img/font.ttf");
	new->text_pos = malloc(sizeof(*(new->text_pos)) * 4);
	new->text = malloc(sizeof(*(new->text)) * 4);
	new->txt_i = 0;
	new->text_pos[0] = new->dial.pos;
	new->text_pos[1].x = new->dial.pos.x + (new->dial.size.x / 3);
	new->text_pos[2].x = new->dial.pos.x + (new->dial.size.x / 2);
	new->text_pos[3].x = new->dial.pos.x + (new->dial.size.x / 3 * 2);
	new->text_pos[1].y = new->dial.pos.y + (new->dial.size.y / 3 * 2);
	new->text_pos[2].y = new->dial.pos.y + (new->dial.size.y / 3 * 2);
	new->text_pos[3].y = new->dial.pos.y + (new->dial.size.y / 3 * 2);
	while (i < 4) {
		new->text[i] = sfText_create();
		sfText_setFont(new->text[i], new->font);
		sfText_setPosition(new->text[i], new->text_pos[i]);
		sfText_setColor(new->text[i], sfBlack);
		sfText_setCharacterSize(new->text[i], new->char_size);
		i += 1;
	}
}

void	new_npc_dial(npc_t *new)
{
	char *s;
	int fd = open("other/dialogues", O_RDONLY);
	int ind = -1;

	s = get_next_line(fd);
	while (s) {
		if (s[0] == '<')
			ind = my_get_index(s);
		if (ind == new->i) {
			fill_bin_tree(new, fd);
			free(s);
			break;
		}
		ind = -1;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}

void	new_npc_rect(npc_t *new, win_t *win)
{
	new->dial.rect = sfRectangleShape_create();
	new->dial.size = (sfVector2f){DIALOG_BOX_SIZEX, DIALOG_BOX_SIZEY};
	new->dial.pos = (sfVector2f){DIALOG_BOX_POSX, DIALOG_BOX_POSY};
	sfRectangleShape_setSize(new->dial.rect, new->dial.size);
	sfRectangleShape_setPosition(new->dial.rect, new->dial.pos);
	sfRectangleShape_setFillColor(new->dial.rect,
	sfColor_fromRGB(245, 222, 179));
	sfRectangleShape_setOutlineColor(new->dial.rect, sfBlack);
	sfRectangleShape_setOutlineThickness(new->dial.rect, 3);
	for (int i = 0; i < 4; i++) {
		new->move[i] = 0;
		new->dir[i] = 1;
	}
	new->pict_rect[0] = (sfIntRect){4 * 32, 1 * 32, 32, 32};
	new->pict_rect[1] = (sfIntRect){2 * 32, 1 * 32, 32, 32};
	new->pict_rect[2] = (sfIntRect){4 * 32, 13 * 32, 32, 32};
	new->pict_rect[3] = (sfIntRect){3 * 32, 1 * 32, 32, 32};
}

void	new_npc(npc_t **npc, char *s, win_t *win)
{
	npc_t *new = malloc(sizeof(*new));
	char **tab = my_str_to_word_array(s, ' ');
	int i = my_getnbr(tab[0]);

	new->i = i;
	new->tree = NULL;
	new->active = -1;
	new->char_size = 46;
	new_npc_rect(new, win);
	new_npc_text(new);
	new_npc_dial(new);
	new_npc_spr(new, tab, win);
	new_npc_move(new);
	init_cursor(new);
	new->next = *npc;
	if (new->next != NULL)
		new->next->prev = new;
	new->prev = NULL;
	*npc = new;
}
