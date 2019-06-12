/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** thomas
*/

#ifndef MY_PARTICLES_H
#define MY_PARTICLES_H

#define PTCL_MNG_CLOCK scene->particle_manager->clock.clock
#define PTCL_MNG_CLOCK_SEC scene->particle_manager->clock.sec
#define PTCL_MNG_CLOCK_MICRO scene->particle_manager->clock.time.microseconds
#define PTCL_MNG_CLOCK_TIME scene->particle_manager->clock.time

struct cntr_info_s {
	sfVector2f *pos;
	sfBool respawn;
	sfVector2i wave;
};
typedef struct cntr_info_s cntr_info_t;

struct p_info_s {
	int states;
	float time;
	float gravity;
	sfVector2i spawn_area;
	sfVector2f pos;
	sfVector2f speed;
	sfVector2f size;
	sfCircleShape *shape;
	int nb_color;
	int color_percent[3][3];
	sfColor *color;
};
typedef struct p_info_s p_info_t;

struct particle_s {
	p_info_t behavior;
	p_info_t stats;
	struct particle_s *next;
	struct particle_s *prev;
};
typedef struct particle_s particle_t;

void	draw_particles(ptcl_contener_t *contener, sfRenderWindow *window);
int	particles_manager(scene_t *scene, win_t *win);
void	new_particle(particle_t *particles_list, p_info_t behavior);
p_info_t	light_behavior(sfVector2f pos);
particle_t	*create_root_particle();
ptcl_contener_t	*create_ptcl_contener(ptcl_contener_t *root,
	void *manager, void *spawn, cntr_info_t info);
void	manage_light_particles(particle_t **particles,
sfVector2i *prtcl_wave, sfBool reset, sfVector2f pos);
void	contenr_manager(scene_t *scene, win_t *win);
p_info_t	light_behavior2(sfVector2f pos);
void	print_conteners(ptcl_contener_t *root);
void	print_conteners2(ptcl_contener_t *root);
void	manage_light_particles2(particle_t **particles,
sfVector2i *prtcl_wave, sfBool reset, sfVector2f pos);
void	new_particle(particle_t *particles_list, p_info_t behavior);
void	new_particle_next(particle_t *particles_list, p_info_t behavior,
	particle_t *particle);
int	random_color_from_percent(int color_percent[3][3], int nb, sfColor
*color);
sfVector2f	create_spawn(sfVector2f pos, sfVector2i area);
ptcl_contener_t	*create_ptcl_contener_root(void);
particle_t	*create_root_particle();
p_info_t	light_behavior_next(p_info_t prev);
p_info_t	light_behavior(sfVector2f pos);
void	manage_light_particles(particle_t **particles, sfVector2i
*prtcl_wave, sfBool reset, sfVector2f pos);
void	light_contenr_manager(scene_t *scene, win_t *win);
void	draw_particles(ptcl_contener_t *root, sfRenderWindow *window);
void	refresh_rect(sfCircleShape *shp, sfVector2f pos, sfVector2f sz,
sfColor c);
void	kill_particle(particle_t *particle, particle_t **real);
int	particles_manager(scene_t *scene, win_t *win);
void	contener_manager(scene_t *scene, win_t *win);
void	spawn_light_particle(ptcl_contener_t *tmp, win_t *win);
p_info_t	dead_behavior_next(p_info_t prev);
p_info_t	dead_behavior(sfVector2f pos);
void	manage_dead_particles(particle_t **particles,
	sfVector2i *prtcl_wave, sfBool reset, sfVector2f pos);
void	spawn_dead_particle(ptcl_contener_t *tmp, win_t *win);
void	kill_contener(particle_t **particle, ptcl_contener_t **cntr);
void	refresh_contener(ptcl_contener_t **tmp, ptcl_contener_t **save);


#endif
