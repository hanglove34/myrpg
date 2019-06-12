/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

char	*go_to_next_scene(char *s, int fd, int nb)
{
	s = clean_str(get_next_line(fd));
	while (s != NULL) {
		if (s[0] == '\0') {
			s = clean_str(get_next_line(fd));
			continue;
		}
		if (s[0] == '<' && (nb == -1 || my_getnbr(&s[1]) == nb))
			break;
		s = clean_str(get_next_line(fd));
	}
	return (s);
}

char	*init_scene_start(char *filename, scene_t *scn,
	win_t *win, sfVector3f info)
{
	char *s = NULL;
	int fd = info.x;
	int i = info.y;
	int nb = info.z;

	s = go_to_next_scene(s, fd, nb);
	if (s == NULL)
		return NULL;
	s = clean_str(get_next_line(fd));
	s = get_map(s, fd, &scn[i], win);
	scn[i].entity_manager = create_entity_manager(scn[i].map->height - 1);
	s = clean_str(get_next_line(fd));
	if (my_strcmp(s, "<NPC") == 0)
		s = get_npc(s, fd, &scn[i], win);
	return (s);
}

void	init_targeted_scenes(char *filename, int nb,
	win_t *win, scene_t *scene)
{
	int fd = open(filename, O_RDONLY);
	char *s = NULL;

	nb += 1;
	print_loading_screen(win, 0);
	if (scene[nb - 1].init != 0)
		return;
	init_scene_start(filename, scene, win, (sfVector3f){fd, nb - 1, nb});
	scene[nb - 1].particle_manager = malloc(sizeof(particle_manager_t));
	scene[nb - 1].particle_manager->root_c = create_ptcl_contener_root();
	scene[nb - 1].init = 1;
	s = clean_str(get_next_line(fd));
	if (my_strcmp(s, "<MONSTER") == 0)
		s = get_monster(s, fd, &scene[nb - 1], win);
	move_npc_on_map(scene[nb - 1].npc, scene[nb - 1].map->tr);
	move_ia_cam(scene[nb - 1].monster, scene[nb - 1].map->tr);
	print_loading_screen(win, 10);
}

scene_t	*init_scenes(char *filename, int nb, win_t *win)
{
	scene_t *scn = malloc(sizeof(*scn) * nb);
	int i = 0;
	int fd = open(filename, O_RDONLY);
	char *s = NULL;

	while (i < nb) {
		init_scene_start(filename, scn, win, (sfVector3f){fd, i, -1});
		s = clean_str(get_next_line(fd));
		if (my_strcmp(s, "<MONSTER") == 0)
			s = get_monster(s, fd, &scn[i], win);
		if (i == 1)
			scn[i].map->tr = (sfVector2f){-757, -41};
		move_npc_on_map(scn[i].npc, scn[i].map->tr);
		move_ia_cam(scn[i].monster, scn[i].map->tr);
		scn[i].particle_manager = malloc(sizeof(particle_manager_t));
		scn[i].particle_manager->root_c = create_ptcl_contener_root();
		i++;
	}
	return (scn);
}
