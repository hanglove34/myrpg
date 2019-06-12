/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** erwann
*/

#include "my.h"

static char *my_strdup_static(char const *src, int size)
{
	char *copy;
	int i = 0;

	copy = malloc(size + 1);
	while (i < size){
		copy[i] = src[i];
		i++;
	}
	copy[size] = '\0';
	return (copy);
}

char **create_tab_ptr_static(char const *str, char del)
{
	int i = 0;
	int word = 1;
	char **ptr_tab = NULL;

	while (str[i + 1] != '\0'){
		if ((str[i] != del) && (str[i + 1] == del))
			word++;
		i++;
	}
	ptr_tab = malloc (sizeof(char *) * (word + 1));
	ptr_tab[word] = NULL;
	return (ptr_tab);
}

void add_word_static(char **ptr_tab, int index, char const *word, int len)
{
	char *new = NULL;

	new = my_strdup_static(word, len);
	ptr_tab[index] = new;
}

char	**my_str_to_word_array_static(char *str, char del)
{
	int i = 0;
	int j = 0;
	char **ptr_tab = create_tab_ptr_static(str, del);

	while (*str != '\0') {
		while (str[i] != del && str[i] != '\0')
			i++;
		if (str[i] == del || str[i] == '\0') {
			add_word_static(ptr_tab, j, str, i);
			j++;
		}
		str += i;
		i = 0;
		if (*str == del)
			str++;
	}
	return (ptr_tab);
}
