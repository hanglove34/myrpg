/*
** EPITECH PROJECT, 2017
** read
** File description:
** read
*/

#include "get_next_line.h"

static int	my_strlen(char *str)
{
	int i = 0;

	while (str && str[i])
		i += 1;
	return (i);
}

char	*my_strcat(char *s1, char *s2)
{
	char *new = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	int i = 0;
	int j = 0;

	if (new == NULL)
		return (NULL);
	while (s1 && s1[i]) {
		new[i] = s1[i];
		i += 1;
	}
	while (s2 && s2[j]) {
		new[i + j] = s2[j];
		j += 1;
	}
	new[i + j] = '\0';
	return (new);
}

static int	end_line(char *buffer, char **line, char **extra, int cat)
{
	int i = 0;

	while (buffer[i] != '\0') {
		if (buffer[i] == '\n') {
			buffer[i] = '\0';
			*line = my_strcat(*line, buffer);
			i += 1;
			buffer += i;
			free(*extra);
			*extra = NULL;
			*extra = my_strcat(*extra, buffer);
			return (1);
		}
		i += 1;
	}
	if (cat == 1)
		*line = my_strcat(*line, buffer);
	return (0);
}

static int	init_values(int *i, char **buffer, char **line, char **extra)
{
	if (*i != 0) {
		*buffer = NULL;
		*buffer = my_strcat(*buffer, *extra);
		if (end_line(*buffer, line, extra, 0) == 1)
			return (1);
		*line = my_strcat(*line, *extra);
		*buffer = malloc(sizeof(char) * (READ_SIZE + 1));
	} else {
		*i += 1;
		*extra = NULL;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static int i = 0;
	char *buffer = malloc(sizeof(char) * READ_SIZE + 1);
	static char *extra;
	char *line = NULL;
	int rd = 1;

	if (buffer == NULL || fd == -1)
		return (NULL);
	rd = (init_values(&i, &buffer, &line, &extra) == 1) ? 0: rd;
	while (rd != 0) {
		rd = read(fd, buffer, READ_SIZE);
		if (rd == 0 && i != 0) {
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		rd = (end_line(buffer, &line, &extra, 1) == 1) ? 0 : rd;
	}
	free(buffer);
	return (line);
}
