/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** erwann
*/

#include "my.h"

void	get_cine_num(win_t *win, scene_t scene, int num)
{
	int fd = open("other/cinematique", O_RDONLY);
	if (fd == -1)
		return;
	char *s = get_next_line(fd);
	int n = 0;
	while (s) {
		if (my_getnbr(s) == num) {
			n++;
			win->num_cine = n;
			reset_value(win);
			get_cmd(win, scene);
		}
		n++;
		s = get_next_line(fd);
	}
}

int	multi_cmd(win_t *win, scene_t scene, char **cmd)
{
	char **cmd2;
	for (int i = 0; cmd[i]; i++) {
		while (cmd[i][0] == '>') {
			win->num_cine = 0;
			win->state = 0;
			reset_value(win);
			return (0);
		} if (cmd[i] && cmd[i][0] == 'P') {
			cmd2 = my_str_to_word_array(cmd[i], ':');
			add_list(win, scene, cmd2, 1);
		} if (cmd[i] && cmd[i][0] == 'J') {
			cmd2 = my_str_to_word_array(cmd[i], ':');
			add_list(win, scene, cmd2, 2);
		} while (cmd[i] && cmd[i][0] == 'D') {
			cmd2 = my_str_to_word_array(cmd[i], ':');
			add_list(win, scene, cmd2, 3);
			break;
		}
	}
	win->num_cine++;
}

void	get_cmd(win_t *win, scene_t scene)
{
	int fd = open("other/cinematique", O_RDONLY);
	if (fd == -1)
		return;
	char *s = get_next_line(fd);
	for (int i = 0; s && i < win->num_cine; i++)
		s = get_next_line(fd);
	if (win->cine != NULL)
		free_cine(win);
	char **cmd;
	cmd = my_str_to_word_array(s, ';');
	if (cmd[0] != NULL)
		multi_cmd(win, scene, cmd);
	s = get_next_line(fd);
}
