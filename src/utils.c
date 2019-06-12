/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "my.h"

int	my_strlen(char *str)
{
	int i = 0;

	while (str && str[i])
		i += 1;
	return (i);
}

char	*my_strdup(char *str)
{
	char *new = malloc(sizeof(char) * my_strlen(str) + 1);
	int i = 0;

	while (str && str[i]) {
		new[i] = str[i];
		i += 1;
	}
	new[i] = '\0';
	return (new);
}

int	my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1 && s2 && s1[i]) {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i += 1;
	}
	return (0);
}

char	*my_straddch(char *s1, char c)
{
	char *new = malloc(sizeof(char) * (my_strlen(s1) + 2));
	int i = 0;

	while (s1 && s1[i]) {
		new[i] = s1[i];
		i += 1;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (s1 != NULL)
		free(s1);
	return (new);
}
