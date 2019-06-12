/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	move_ia(win_t *win, monster_t *monster, map_t *map)
{
	monster_t *tmp = monster;
	while (tmp->next && tmp) {
		if (tmp->monster->stat.hp > 0) {
			check_ia(win, tmp, map, monster);
			sfSprite_setTextureRect(tmp->monster->spt,
			tmp->monster->rect);
			sfSprite_setPosition(tmp->monster->spt,
			tmp->monster->pos);
		}
		tmp = tmp->next;
	}
}

void	parse_monster(char *s, scene_t *scenes, win_t *win)
{
	char **tab = my_str_to_word_array(s, ' ');
	int m = 0;
	for (m = 0; tab[m]; m++) {
		for (int n = 0; tab[m][n] != '\0'; n++) {
			if (m > 0 && (tab[m][n] < '0' || tab[m][n] > '9'))
				return;
		}
	}
	if (m != 3)
		return;
	scenes->monster = create_ia_list(scenes->monster, tab[0],
	my_getnbr(tab[1]), my_getnbr(tab[2]));
	set_particle_on_monster(scenes->monster, scenes, win);
}

void	save_value_ia(obj_t *new, int x, int y)
{
	new->rect.left = 0;
	new->rect.top = 0;
	new->offset = 0;
	new->pos.x = (x * 40) + 40;
	new->pos.y = (y * 40) + 40;
	new->pos_tile.x = (x * 40) + 40;
	new->pos_tile.y = (y * 40) + 40;
	new->stat.all_hp = new->stat.hp;
	new->clock.clock = sfClock_create();
	new->spt = sfSprite_create();
	new->stat.xp[0] = 10;
	sfSprite_setOrigin(new->spt, (sfVector2f){new->rect.width / 2,
	new->rect.height});
	sfSprite_setPosition(new->spt, new->pos);
	sfSprite_setTexture(new->spt, new->img, sfTrue);
}

monster_t	*create_ia_list(monster_t *monster, char *name, int x, int y)
{
	rect_shape_t rect;
	monster_t *new = malloc(sizeof(*new));
	new->monster = create_ia(name, x, y);
	new->clock.clock = sfClock_create();
	new->alpha = 255;
	new->pos = new->monster->pos.y - (new->monster->rect.height);
	new->next = monster;
	init_background_inv(&rect,(sfVector2f){70,6},(sfIntRect){255,0,0,255});
	new->hp = rect;
	new->mul = 1;
	sfRectangleShape_setPosition(new->hp.rect, (sfVector2f)
	{new->monster->pos.x-35,new->monster->pos.y-new->monster->rect.height});
	init_background_inv(&rect, (sfVector2f){70, 6},
	(sfIntRect){255, 255, 255, 255});
	new->hp2 = rect;
	sfRectangleShape_setPosition(new->hp2.rect,
	(sfVector2f){new->monster->pos.x - 35, new->monster->pos.y -
	new->monster->rect.height});
	monster = new;
	return (monster);
}

obj_t	*create_ia(char *name, int x, int y)
{
	int fd = open("other/ennemi", O_RDONLY);
	obj_t *new = malloc(sizeof(obj_t));
	char *str = get_next_line(fd);
	while (my_strcmp(name, str) != 0)
		str = get_next_line(fd);
	str = clean_str(get_next_line(fd));
	new->img = sfTexture_createFromFile(str, NULL);
	char **rect = my_str_to_word_array(clean_str(get_next_line(fd)), ',');
	new->rect.width = my_getnbr(rect[0]);
	new->rect.height = my_getnbr(rect[1]);
	new->stat.armor = my_getnbr(clean_str(get_next_line(fd)));
	new->stat.hp = my_getnbr(clean_str(get_next_line(fd)));
	new->stat.atk = my_getnbr(clean_str(get_next_line(fd)));
	new->stat.spd = my_getnbr(clean_str(get_next_line(fd)));
	new->stat.mana = my_getnbr(clean_str(get_next_line(fd)));
	new->stat.crit = my_getnbr(clean_str(get_next_line(fd)));
	new->name = my_strdup(name);
	save_value_ia(new, x, y);
	return (new);
}
