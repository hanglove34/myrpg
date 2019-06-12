/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** erwann
*/

#ifndef ENTITIES_H_
#define ENTITIES_H_

typedef enum
{
	NONE,
	SPRITE,
}DrawType;

struct entity_s {
	int x;
	int y;
	sfVector2f real_pos;
	int priority;
	DrawType type;
	void *shape;
	void (*draw)(DrawType type, void *shape, sfRenderWindow * w);
	struct entity_s *next;
	struct entity_s *prev;
};
typedef struct entity_s entity_t;

void	kill_entity(entity_t *entity, monster_t *tmp);
void	remove_entity(entity_t *entity, entity_t *list);
void	add_entity(entity_t *entity, entity_t *list);
void	draw_entity(DrawType type, void *shape, sfRenderWindow *w);
entity_t	*create_root_entity();
entity_t **create_entity_manager(int size);
entity_t	*create_entity(sfVector2f pos, DrawType name, void *shape,
int prio);
void	manage_entity(win_t *win, scene_t *scene);
void	manage_entity_after(win_t *win, scene_t *scene);

#endif
