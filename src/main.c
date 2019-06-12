/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	init_heros_stat(win_t *win)
{
	win->heros.stat.hp = 40;
	win->heros.stat.armor = 15;
	win->heros.stat.atk = 8;
	win->heros.stat.crit = 0;
	win->heros.stat.mana = 10;
	win->heros.stat.spd = 3;
	win->heros.stat.lvl = 1;
	win->heros.stat.gold = 0;
	srand(time(NULL));
}

void	init_heros(win_t *win)
{
	win->num_cine = 0;
	win->scene = 1;
	inits_t val = inits_pos_rect(&val, (sfVector2f){1070, 360},
	(sfIntRect){78, 0, 128, 155}, (sfVector2f){1, 1});
	win->heros = *create_object("img/heros.png", val, 3, HERO);
	sfSprite_setOrigin (win->heros.spt, (sfVector2f){70, 132});
	init_heros_stat(win);
	win->heros.stat.txt = malloc(sizeof(text_t) * 7);
	for (int i = 0; i < 9; i++)
		win->heros.state[i] = -1;
	win->heros.state[7] = 0;
	win->heros.stat.xp[0] = 0;
	win->heros.stat.xp[1] = 20;
	win->heros.origin = (sfIntRect){0, 155, 0, 0};
	win->purse = NULL;
	win->clock.clock = sfClock_create();
	win->heros.entity = create_entity(win->heros.real_pos,
	SPRITE, win->heros.spt, 0);
}

void	init_window(win_t *win)
{
	win->mode.width = WIDTH;
	win->mode.height = HEIGHT;
	win->mode.bitsPerPixel = 32;
	win->win = sfRenderWindow_create(win->mode, "Elkia", 0 |
	sfClose, NULL);
	sfRenderWindow_setKeyRepeatEnabled(win->win, sfFalse);
	settings_init(win);
	win->cine = new_list();
	init_heros(win);
	inits_t val = inits_pos_rect(&val, (sfVector2f){0, 0},
	(sfIntRect){0, 0, 109, 120}, (sfVector2f){1, 1});
	win->spell = create_object("img/fire_spell.png", val, 3, HERO);
	win->spell->state[0] = -1;
	win->ver[3] = 0;
	win->info.init = 0;
	init_inventory(win);
	init_music_menu(win);
	create_menu(win);
	init_quests(win);
	sfRenderWindow_setFramerateLimit(win->win, 90);
}

scene_t	*create_scene(int nb)
{
	scene_t *scn = malloc(sizeof(*scn) * nb);
	int i = 0;

	while (i < nb) {
		scn[i].init = 0;
		scn[i].tp = 1;
		i++;
	}
	return (scn);
}

int	main(void)
{
	if (secure_config() == -1) {
		write(2, "Don't modify the config files !\n", 32);
		return (0);
	}
	win_t win;
	init_window(&win);
	map_t *map = NULL;
	scene_t *scene = create_scene(NB_SCENE);

	init_targeted_scenes("other/scene", win.scene, &win, scene);
	while (sfRenderWindow_isOpen(win.win)) {
		if (win.state <= 1)
			game(&win, scene);
		if (win.state > 1)
			menu(&win, &scene);
	}
	free_music(&win);
	destroy_hero_death_struc(&win.info);
}
