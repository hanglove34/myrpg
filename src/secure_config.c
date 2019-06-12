/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

long int	give_key(int fd)
{
	int rd;
	char buffer[1];
	int i = 1;
	long int key = 0;

	rd = read(fd, buffer, 1);
	while (rd != -1 && rd != 0) {
		key += i * buffer[0];
		i += 1;
		rd = read(fd, buffer, 1);
	}
	return (key);
}

int	compare_keys(long int keys[22], char *files[22])
{
	int fd;

	for (int i = 0; i < 22; i += 1) {
		fd = open(files[i], O_RDONLY);
		if (fd == -1 || give_key(fd) != keys[i])
			return (-1);
		close(fd);
	}
	return (0);
}

int	secure_config(void)
{
	long int keys[22] = {0X1E034FE1, 0XA214EC, 0X13A11499, 0X39AED4,
	0X4898F92, 0X9DFF27, 0X1073D207, 0X19C77E96A, 0XDDB645B5, 0X186EED3A9C,
	0X3A60084C2, 0X48BAAA416, 0X10D7D0C56, 0XC9BC10B1, 0XAB20A0748,
	0X23F681EDC, 0X1FB35AE47, 0X41457DA85, 0XBAE2850B4, 0X305D045C1,
	0X7C5207D7, 0X409DEB86B};
	char *files[22] = {"other/cinematique", "other/credits",
	"other/dialogues", "other/ennemi", "other/item",
	"other/quest", "other/scene", "maps/act_one/boss_castle.txt",
	"maps/act_one/caserne.txt", "maps/act_one/castle_entrance.txt",
	"maps/act_one/castle.txt", "maps/act_one/gate.txt",
	"maps/act_one/grotte.txt", "maps/act_one/intro.txt",
	"maps/act_one/map.txt", "maps/act_one/town.txt",
	"maps/act_two/boss_wood.txt", "maps/act_two/deep_wood.txt",
	"maps/act_two/forest_camp.txt", "maps/act_two/forest_entrance.txt",
	"maps/act_two/forge.txt", "maps/act_two/military_camp.txt"};
	return (compare_keys(keys, files));
}
