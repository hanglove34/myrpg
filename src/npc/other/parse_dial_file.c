/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

char	*get_single_str(char *str, int *i, int fd)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
	int j = 0;

	while (str[*i] && str[*i] != 34)
		*i += 1;
	*i += 1;
	while (str[*i] != '>' && str[*i] != 34) {
		new[j] = str[*i];
		j += 1;
		*i += 1;
		if (!str[*i]) {
			free(str);
			str = get_next_line(fd);
			*i = 1;
		}
	}
	new[j] = '\0';
	*i += 1;
	return (new);
}

void	get_third_prop(tree_t *tree, int *i, char *str)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
	int j = 0;

	if (str[*i] != ';') {
		while (str[*i] && str[*i] != 34)
			*i += 1;
		*i += 1;
		for (j = 0; str[*i] && str[*i] != 34; j++, (*i)++)
			new[j] = str[*i];
		new[j] = '\0';
		tree->rightstr = my_strdup(new);
		free(new);
	}
}

void	get_second_prop(tree_t *tree, int *i, char *str)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
	int j = 0;

	while (str[*i] && str[*i] != 34)
		*i += 1;
	*i += 1;
	for (j = 0; str[*i] && str[*i] != 34; j++, (*i)++)
		new[j] = str[*i];
	*i += 1;
	new[j] = '\0';
	tree->midstr = my_strdup(new);
	free(new);
	get_third_prop(tree, i, str);
}

void	get_prop_str(tree_t *tree, int *i, char *str)
{
	char *new = malloc(sizeof(char) * (my_strlen(str) + 1));
	int j = 0;

	while (str[*i] && str[*i] != 34)
		*i += 1;
	*i += 1;
	for (j = 0; str[*i] && str[*i] != 34; j++, (*i)++)
		new[j] = str[*i];
	*i += 1;
	new[j] = '\0';
	tree->leftstr = my_strdup(new);
	free(new);
	get_second_prop(tree, i, str);
}

int	my_get_index(char *str)
{
	int i = 1;
	int nb = 0;

	while (str[i] >= '0' && str[i] <= '9') {
		nb = (nb * 10) + (str[i] - 48);
		i += 1;
	}
	return (nb);
}
