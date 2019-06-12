/*
** EPITECH PROJECT, 2018
** init_inventory
** File description:
** my_rpg
*/

#include "my.h"

void	more_init_pict_stat(obj_t *pict)
{
	inits_t gold = inits_pos_rect(&gold, (sfVector2f){1020, 600},
	(sfIntRect){3 * 32, 13 * 32, 32, 32}, (sfVector2f){1.7, 1.7});
	pict[6] = *create_object("img/item.png", gold, 1, EMPTY);
}

void	init_pict_stat(obj_t *pict)
{
	inits_t hp = inits_pos_rect(&hp, (sfVector2f){470, 230},
	(sfIntRect){32, 0, 32, 32}, (sfVector2f){1.7, 1.7});
	pict[0] = *create_object("img/item.png", hp, 1, EMPTY);
	inits_t armor = inits_pos_rect(&armor, (sfVector2f){470, 285},
	(sfIntRect){256, 0, 32, 32}, (sfVector2f){1.7, 1.7});
	pict[1] = *create_object("img/item.png", armor, 1, EMPTY);
	inits_t atk = inits_pos_rect(&atk, (sfVector2f){470, 340},
	(sfIntRect){224, 0, 32, 32}, (sfVector2f){1.7, 1.7});
	pict[2] = *create_object("img/item.png", atk, 1, EMPTY);
	inits_t crit = inits_pos_rect(&crit, (sfVector2f){470, 395},
	(sfIntRect){352, 0, 32, 32}, (sfVector2f){1.7, 1.7});
	pict[3] = *create_object("img/item.png", crit, 1, EMPTY);
	inits_t spd = inits_pos_rect(&spd, (sfVector2f){470, 450},
	(sfIntRect){416, 0, 32, 32}, (sfVector2f){1.7, 1.7});
	pict[4] = *create_object("img/item.png", spd, 1, EMPTY);
	inits_t mana = inits_pos_rect(&mana, (sfVector2f){470, 505},
	(sfIntRect){192, 96, 32, 32}, (sfVector2f){1.7, 1.7});
	pict[5] = *create_object("img/item.png", mana, 1, EMPTY);
	more_init_pict_stat(pict);
}
