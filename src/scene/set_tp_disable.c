/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

void	set_tp_disable(scene_t *scene)
{
	int i = 0;

	while (i < NB_SCENE) {
		switch(i) {
			case 2:
				scene[i].tp = 0;
				break;
			case 4:
				scene[i].tp = 0;
				break;
			case 11:
				scene[i].tp = 0;
				break;
		}
		i++;
	}
}

void	enable_tp(scene_t *scene, quest_t *quest)
{
	switch (quest->nb) {
		case 3:
			scene[2].tp = 1;
			break;
		case 4:
			scene[4].tp = 1;
			break;
		case 5:
			scene[11].tp = 1;
			break;
	}
}
