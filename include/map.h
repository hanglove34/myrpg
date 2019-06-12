/*
** EPITECH PROJECT, 2017
** rush1
** File description:
** thomas fdp
*/

#ifndef MAP_MAP_H_
#define MAP_MAP_H_
#define SCALE_MAP 40

struct quad_s {
	sfVector2f p1;
	sfVector2f p2;
	sfVector2f p3;
	sfVector2f p4;
};
typedef struct quad_s myquad_t;

struct line_s {
	sfVector2f p1;
	sfVector2f p2;
};
typedef struct line_s myline_t;

typedef struct tilesets_s
{
	char *filename;
	int w;
	int h;
} tilesets_t;

typedef struct linkedlist_s
{
	int index;
	struct linkedlist_s *next;
} ll_t;

typedef struct info_tex_s
{
	sfVector2i info;
	char *filename;
	int rmd;
	int *n;
} info_tex_t;

struct map_s {
	int size;
	sfVertexArray **vtx_arr;
	sfTexture **tex;
	int nb_tex;
	int nb_tileset;
	int weidth;
	int height;
	int stage;
	int player_stage;
	int **map_event;
	int **sols;
	int **decores;
	int **colisions;
	int nb_map_event;
	int nb_sols;
	int nb_decores;
	int nb_colisions;
	sfVector2f tr;
	int height_heros_2d;
	int event;

};

typedef struct info_map_s
{
	ll_t *index_used;
} info_map_t;

typedef struct pos_map_s {
	sfVector2f pos;
	sfVector2f tr;
} pos_map_t;

typedef struct map_s map_t;
sfVertexArray	**create_vtx_arr_tab(int weidth, int height);
map_t	*my_create_map(char *name, win_t *win, pos_map_t info);
void	refresh_map_vtx_arr(sfVertexArray **VtxAr, map_t *map);
void	my_draw_window(sfRenderWindow *w, map_t *map, win_t *win, scene_t
scene);
int	test_colision (sfVector2f coord, sfVector2f offset, map_t *map);
void	create_col_stage(map_t *map, int stage, char *filename);
void	print_col_map(map_t *map, int stage);
int	in_map(sfVector2f w_coord, sfVector2f offset, map_t *map);
char	*fill_index_map(char *s, int *map, int fd);
int	test_colision_around_character(map_t *map, win_t *win, int index);
int	init_all_tileset_and_launch_map_config(map_t *map,
	char *filename, win_t *win);
int	move_type_x(win_t *win, map_t *map, int offset);
int	move_type_y(win_t *win, map_t *map, int offset);
void	map_events(win_t *win, scene_t *scene);
int	test_event(win_t *win, map_t *map, sfVector2f offset);
void	print_linkedlist(ll_t *list);
int	**get_maps(char *filename, map_t *map, char *name, ll_t **list);
char	**my_str_to_word_array_static(char *str, char del);
int	my_strncmp(char const *s1, char const *s2, int n);
int	number_of_sol(char *filename, char *name);
void	add_index_used(ll_t **list, int index);
sfTexture **get_tex(char **tilesets_name, tilesets_t tileset[], ll_t *list,
map_t *map);
int	add_textures_in_tex(sfTexture **tex, sfVector2i info, char *filename,
ll_t *list);
char	**get_tilesets(char *filename, int *w, int *h, map_t *map);
char	**my_str_to_word_array_static(char *str, char del);
sfVertexArray	**create_vtx_arr_tab(int weidth, int height);
void	destroy_vertex_arr(sfVertexArray **vtx_arr, map_t *map);
void	destroy_map(map_t *map);
int	number_of_sol(char *filename, char *name);
void	switch_scene(win_t *win, scene_t *scene, int nb);
void	switch_scene_town(win_t *win, scene_t *scene, int nb);
void	switch_scene_castle(win_t *win, scene_t *scene, int nb);
void	my_switch_scene(int nb, sfFloatRect rect, scene_t
*scene, win_t *win);
char	*get_map(char *s, int fd, scene_t *scenes, win_t *win);
char	*get_npc(char *s, int fd, scene_t *scenes, win_t *win);
char	*get_monster(char *s, int fd, scene_t *scenes, win_t *win);
void	draw_objects(scene_t scene, sfRenderWindow *w,
	sfVector2i coord, win_t * win);
void	refresh_rectangle(sfRectangleShape *shp, sfVector2f pos,
	sfVector2f sz, sfColor c);
void	print_loading_screen(win_t *win, int nb);
myquad_t init_quad(int i, int j, map_t *map);
void	switch_act_two_part_one(win_t *win, scene_t *scene, int nb);
void	set_tp_disable(scene_t *scene);
void	switch_scene_act_one(win_t *win, scene_t *scene, int nb);
#define MAP_VTX map->vtx_arr
#define WEIDTH_MAP map->weidth
#define HEIGHT_MAP map->height
#endif /* MAP_MAP_H_ */
