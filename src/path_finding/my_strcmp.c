/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** erwann broye hombert
*/

int	my_strcmp(char const *s1, char const *s2)
{
	int compt;

	compt = 0;
	while (s1[compt] != '\0' && s2[compt] != '\0') {
		if (s1[compt] != s2[compt])
			return (s1[compt] - s2[compt]);
		compt++;
	}
	return (0);
}
