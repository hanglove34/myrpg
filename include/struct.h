/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** erwann
*/

#ifndef STRUCT_H_
#define STRUCT_H_

struct win_s;
struct scene;
typedef struct npc npc_t;
typedef struct entity_s entity_t;

typedef struct text_s
{
	sfText *txt;
	unsigned int size;
	char *str;
	sfFont *font;
	sfVector2f pos;
} text_t;

typedef struct t_node
{
	int state;
	int father[2];
	int cost;
	int distance;
	int total;
} node_t;

typedef struct list_t
{
	int x;
	int y;
	struct list_t *next;
	struct list_t *prev;
} list_t;

typedef struct t_start
{
	int end[2];
	int start[2];
	list_t *open_list;
	list_t *closed_list;
} start_t;

typedef struct stat_s
{
	int all_hp;
	int stat_end[6];
	int armor;
	int hp;
	int lvl;
	int atk;
	int spd;
	int mana;
	int crit;
	int xp[2];
	int gold;
	text_t *txt;
} stat_t;

typedef enum type {
	BUTTON,
	IMAGE,
	HERO,
	ARMOR,
	WEAPON,
	HELMET,
	SHIELD,
	SHOE,
	LIFE,
	INV,
	EMPTY,
} object_t;

typedef struct inits_s
{
	sfVector2f pos;
	sfIntRect rect;
	sfVector2f scale;
} inits_t;

typedef struct clck
{
	sfClock *clock;
	sfTime time;
	float sec;
} clck_t;

typedef struct ptcl_contener_s ptcl_contener_t;

typedef struct game_object
{
	sfSprite *spt;
	object_t type;
	sfTexture *img;
	sfIntRect rect;
	sfVector2f pos;
	sfVector2f real_pos;
	sfVector2i pos_tile;
	sfVector2i coord;
	sfIntRect origin;
	int state[9];
	sfText *text;
	float speed;
	int offset;
	clck_t clock;
	int ver;
	stat_t stat;
	text_t txt;
	entity_t *entity;
	void (*ptr_cmd)(struct win_s *, struct scene *);
	void (*reset)(struct win_s *, struct scene **);
	char *name;
	ptcl_contener_t *cntr;
} obj_t;

typedef struct loot_s
{
	obj_t add;
	int item;
	int del;
	struct loot_s *next;
} loot_t;

typedef struct purse_s
{
	int map;
	int ver;
	sfVector2f pos;
	int *item;
	obj_t sprt;
	loot_t *loot;
	struct purse_s *next;
} purse_t;

typedef struct	rect_shape {
	sfRectangleShape *rect;
	sfVector2f pos;
	sfVector2f size;
} rect_shape_t;

typedef struct menu_t
{
	sfSprite *spt;
	sfTexture *img;
	sfIntRect rect;
	sfVector2f pos;
	sfText *text;
	float speed;
	obj_t button[12];
	int offset;
	clck_t clock;
} menu_t;

typedef struct monster
{
	obj_t *monster;
	int mul;
	clck_t clock;
	rect_shape_t hp;
	rect_shape_t hp2;
	sfText *text;
	int pos;
	int alpha;
	struct monster *next;
} monster_t;

typedef struct mouse_s
{
	sfVector2f pos;
	int item;
	int ver;
	int inv;
	object_t type;
	sfVector2f save;
	int cp;
} mouse_t;

typedef struct quest {
	int nb;
	int state;
	void (*valid)(struct win_s *, struct quest *, struct scene *);
	text_t text;
	char *longer_str;
	rect_shape_t rect;
	sfVector2f rect_pos;
	struct quest *prev;
	struct quest *next;
} quest_t;

typedef struct music_s
{
	sfMusic *music;
	int state;
} music_t;

typedef struct quest_book {
	int state[3];
	int page;
	int max_page;
	sfTexture *tex;
	sfSprite *spr;
	sfText *page_nb[5];
	int nb_rewards[5];
	sfText *quest_txt[5];
	sfText *reward_txt[5];
	sfText *status_txt[4];
	sfRectangleShape *rect[2];
	sfSprite **rewards[5];
} quest_book_t;

typedef struct cinematique {
	int num;
	char *type;
	char *axe;
	int pos;
	int origin;
	struct cinematique *next;
	struct cinematique *prev;
} cine_t;

typedef struct win_anim_s {
	sfTexture *texture;
	sfText *text;
	sfColor color;
	sfImage *img;
	sfRectangleShape *shp;
	sfIntRect area;
	clck_t clock;
	int centiseconds;
	int init;
} win_anim_t;

typedef struct win_s
{
	sfRenderWindow *win;
	sfVideoMode mode;
	sfEvent evt;
	sfFont *font;
	obj_t heros;
	int state;
	quest_book_t quest_book;
	quest_t *quest;
	menu_t menu;
	int num_cine;
	clck_t clock;
	cine_t *cine;
	music_t *music;
	music_t *sound;
	obj_t *invent;
	obj_t *item;
	obj_t *pict;
	obj_t *spell;
	mouse_t mouse;
	obj_t character;
	purse_t *purse;
	rect_shape_t *background;
	sfText *lvl;
	sfTexture *hp_tex;
	sfSprite *hp_spr;
	int scene;
	int num_music;
	int volmusic;
	int luminosity;
	int ver[4];
	win_anim_t info;
} win_t;

typedef struct tree {
	int type;
	int quest_nb;
	int offset;
	char *main;
	char *leftstr;
	char *midstr;
	char *rightstr;
	struct tree *left;
	struct tree *mid;
	struct tree *right;
	struct tree *already;
	struct tree *quest;
	struct tree *prev;
} tree_t;

typedef struct ans_curs {
	sfTexture *tex;
	sfSprite *spr;
	sfVector2f *pos;
	int answer;
	int state;
	void (*fptr)(struct ans_curs curs);
	clck_t blink;
} ans_curs_t;

typedef enum npc_type {
	NORM,
	MERCH,
	SAVE,
} npc_type_t;

typedef struct merch_item {
	int nb;
	sfSprite *square;
	sfSprite *item;
	char **stat_str;
	sfVector2f pos;
	int state[2];
	struct merch_item *prev;
	struct merch_item *next;
} merch_item_t;

typedef struct merch {
	sfRectangleShape *rect;
	sfTexture *buy_tex;
	sfTexture *rect_tex;
	sfSprite *buy;
	sfSprite *mouse;
	sfSprite *sell;
	char *sum_str;
	char *sell_str;
	sfSprite *left_arrow;
	sfSprite *right_arrow;
	sfText *stat[8];
	sfSprite *pict[8];
	int state;
	sfSprite *close;
	merch_item_t *items;
} merch_t;

typedef struct npc {
	npc_type_t type;
	int i;
	sfFont *font;
	int char_size;
	int state[4];
	int dir[4];
	int move[4];
	sfText **text;
	sfVector2f *text_pos;
	int txt_i;
	sfTexture *tex;
	sfSprite *spr;
	sfSprite *dial_spr;
	sfSprite *pict;
	sfIntRect pict_rect[4];
	int pict_move[2];
	sfIntRect rect[4];
	sfIntRect move_rect[4][3];
	sfVector2f pos;
	rect_shape_t dial;
	ans_curs_t cursor;
	int active;
	clck_t clocks[3];
	tree_t *tree;
	merch_t merch;
	struct npc *prev;
	struct npc *next;
} npc_t;

typedef struct map_s map_t;
typedef struct particle_s particle_t;
typedef struct particle_manager_s particle_manager_t;

typedef struct particle_manager_s {
	particle_t *root;
	ptcl_contener_t *root_c;
	clck_t clock;
}particle_manager_t;


typedef struct ptcl_contener_s {
	particle_t *root;
	sfVector2i prtcl_wave;
	sfBool bool;
	void (*fptr)(particle_t **particles, sfVector2i *prtcl_wave, sfBool
	reset, sfVector2f pos);
	void (*spawn)(ptcl_contener_t *tmp, win_t *win);
	sfVector2f *pos;
	sfBool respawn;
	ptcl_contener_t *next;
	ptcl_contener_t *prev;
}ptcl_contener_t;

typedef struct scene {
	map_t *map;
	npc_t *npc;
	monster_t *monster;
	particle_manager_t *particle_manager;
	entity_t **entity_manager;
	int init;
	int tp;
} scene_t;


#endif
