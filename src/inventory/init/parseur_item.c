/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

object_t	def_type_item(int nb)
{
	while (nb == 1)
		return (ARMOR);
	while (nb == 2)
		return (WEAPON);
	while (nb == 3)
		return (HELMET);
	while (nb == 4)
		return (SHIELD);
	while (nb == 5)
		return (SHOE);
	while (nb == 6)
		return (LIFE);
}

char	*delete_tab(char *str)
{
	int c = 0;
	int nb = 0;
	char *save = malloc(sizeof(char) * my_strlen(str));

	while (str[c]) {
		if (str[c] == '\t') {
			c++;
		} else {
			save[nb] = str[c];
			c++;
			nb++;
		}
	}
	free(str);
	save[nb] = '\0';
	return (save);
}

void	init_parseur_base(obj_t *item, char *str, int nb)
{
	char **stat = my_str_to_word_array(str, ';');
	stat[0] = delete_tab(stat[0]);
	sfVector2f pos = {my_getnbr(stat[1]), my_getnbr(stat[2])};
	sfIntRect rect = {my_getnbr(stat[3]), my_getnbr(stat[4]),
	my_getnbr(stat[5]), my_getnbr(stat[6])};
	sfVector2f size = {(float)my_getnbr(stat[7])/100,
	(float)my_getnbr(stat[8])/100};
	char *path = stat[9];
	object_t type = def_type_item(my_getnbr(stat[10]));
	inits_t armor = inits_pos_rect(&armor, pos, rect, size);
	item[nb] = *create_object(path, armor, 1, type);
	item[nb].state[0] = my_getnbr(stat[0]);
}

void	init_parseur_stat(obj_t *item, char *str, int nb)
{
	char **stat = my_str_to_word_array(str, ';');
	stat[0] = delete_tab(stat[0]);
	item[nb].stat.atk = my_getnbr(stat[0]);
	item[nb].stat.spd = my_getnbr(stat[1]);
	item[nb].stat.hp = my_getnbr(stat[2]);
	item[nb].stat.armor = my_getnbr(stat[3]);
	item[nb].stat.mana = my_getnbr(stat[4]);
	item[nb].stat.crit = my_getnbr(stat[5]);
	item[nb].stat.gold = my_getnbr(stat[6]);
}
