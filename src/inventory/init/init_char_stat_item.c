/*
** EPITECH PROJECT, 2018
** event_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	init_char_name_stat(obj_t *item)
{
	item[0].stat.txt = malloc(sizeof(text_t) * 6);
	text_init(&item[0].stat.txt[0], "HP :", (sfVector2f){0, 0}, 17);
	text_init(&item[0].stat.txt[1], "ARMOR :", (sfVector2f){0, 0}, 17);
	text_init(&item[0].stat.txt[2], "ATK :", (sfVector2f){0, 0}, 17);
	text_init(&item[0].stat.txt[3], "CRIT :", (sfVector2f){0, 0}, 17);
	text_init(&item[0].stat.txt[4], "SPD :", (sfVector2f){0, 0}, 17);
	text_init(&item[0].stat.txt[5], "MANA :", (sfVector2f){0, 0}, 17);
}

void	init_char_stat_item(obj_t *item, int c)
{
	int nb = 1;

	init_char_name_stat(item);
	for (;nb != c; nb++) {
		item[nb].stat.txt = malloc(sizeof(text_t) * 6);
		text_init(&item[nb].stat.txt[0], my_getstr(item[nb].stat.hp),
		(sfVector2f){0, 0}, 17);
		text_init(&item[nb].stat.txt[1], my_getstr(item[nb].stat.armor)
		, (sfVector2f){0, 0}, 17);
		text_init(&item[nb].stat.txt[2], my_getstr(item[nb].stat.atk),
		(sfVector2f){0, 0}, 17);
		text_init(&item[nb].stat.txt[3], my_getstr(item[nb].stat.crit),
		(sfVector2f){0, 0}, 17);
		text_init(&item[nb].stat.txt[4], my_getstr(item[nb].stat.spd),
		(sfVector2f){0, 0}, 17);
		text_init(&item[nb].stat.txt[5], my_getstr(item[nb].stat.mana),
		(sfVector2f){0, 0}, 17);
	}
}

void	init_basique_stat_heros(win_t *win)
{
	win->heros.stat.stat_end[0] = win->heros.stat.hp;
	win->heros.stat.stat_end[1] = win->heros.stat.armor;
	win->heros.stat.stat_end[2] = win->heros.stat.atk;
	win->heros.stat.stat_end[3] = win->heros.stat.crit;
	win->heros.stat.stat_end[4] = win->heros.stat.spd;
	win->heros.stat.stat_end[5] = win->heros.stat.mana;

}

void	init_struct_display_stat_heros(win_t *win)
{
	init_basique_stat_heros(win);
	text_init(&win->heros.stat.txt[0],
	my_getstr(win->heros.stat.stat_end[0]), (sfVector2f){550, 245}, 30);
	text_init(&win->heros.stat.txt[1],
	my_getstr(win->heros.stat.stat_end[1]), (sfVector2f){550, 295}, 30);
	text_init(&win->heros.stat.txt[2],
	my_getstr(win->heros.stat.stat_end[2]), (sfVector2f){550, 350}, 30);
	text_init(&win->heros.stat.txt[3],
	my_getstr(win->heros.stat.stat_end[3]), (sfVector2f){550, 405}, 30);
	text_init(&win->heros.stat.txt[4],
	my_getstr(win->heros.stat.stat_end[4]), (sfVector2f){550, 460}, 30);
	text_init(&win->heros.stat.txt[5],
	my_getstr(win->heros.stat.stat_end[5]), (sfVector2f){550, 520}, 30);
	text_init(&win->heros.stat.txt[6],
	my_getstr(win->heros.stat.gold), (sfVector2f){1080, 605}, 30);
	win->heros.stat.all_hp = win->heros.stat.stat_end[0];
}
