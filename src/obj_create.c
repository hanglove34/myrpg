/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "include.h"

inits_t	inits_pos_rect(inits_t *val, sfVector2f pos, sfIntRect rect,
	sfVector2f scale)
{
	val->pos.x = pos.x;
	val->pos.y = pos.y;
	val->rect.left = rect.left;
	val->rect.top = rect.top;
	val->rect.width = rect.width;
	val->rect.height = rect.height;
	val->scale.x = scale.x;
	val->scale.y = scale.y;
	return (*val);
}

obj_t *create_object(const char *path, inits_t val, int speed, object_t type)
{
	obj_t *new = malloc(sizeof(obj_t));
	new->spt = sfSprite_create();
	new->speed = speed;
	new->type = type;
	new->rect.left = val.rect.left;
	new->rect.top = val.rect.top;
	new->rect.width = val.rect.width;
	new->rect.height = val.rect.height;
	new->pos.x = val.pos.x;
	new->pos.y = val.pos.y;
	new->clock.clock = sfClock_create();
	new->offset = 0;
	new->img = sfTexture_createFromFile(path, NULL);
	sfSprite_scale(new->spt, val.scale);
	sfSprite_setPosition(new->spt, val.pos);
	sfSprite_setTexture(new->spt, new->img, sfTrue);
	sfSprite_setTextureRect(new->spt, new->rect);
	return (new);
}
