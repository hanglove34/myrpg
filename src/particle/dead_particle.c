/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** thomas
*/

#include "my.h"

p_info_t	dead_behavior_next(p_info_t prev)
{
	p_info_t behavior = prev;

	behavior.color = malloc(sizeof(*behavior.color) * behavior.nb_color);
	behavior.color[0] = sfColor_fromRGBA(0x00, 0x00, 0x00, 200);
	behavior.color[1] = sfColor_fromRGBA(0xFF, 0xFF, 0xFF, 200);
	behavior.color_percent[0][0] = 75;
	behavior.color_percent[0][1] = 99;
	behavior.color_percent[0][2] = 25;
	behavior.color_percent[1][0] = 25;
	behavior.color_percent[1][1] = 24;
	behavior.color_percent[1][2] = 0;
	return (behavior);
}

p_info_t	dead_behavior(sfVector2f pos)
{
	p_info_t behavior;

	pos = (sfVector2f){pos.x - 30, pos.y - 90};
	behavior.states = 1;
	behavior.time = rand() % 5 + 12;
	behavior.gravity = 9;
	behavior.spawn_area = (sfVector2i){50, 50};
	behavior.pos = create_spawn(pos, behavior.spawn_area);
	behavior.size = (sfVector2f){2, 2};
	behavior.speed = (sfVector2f){0, -(3.2 + (1 / (2 + rand() % 8)))};
	behavior.shape = NULL;
	behavior.nb_color = 2;
	behavior = dead_behavior_next(behavior);
	return (behavior);
}
