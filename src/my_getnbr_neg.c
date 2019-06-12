/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** erwann
*/

int	my_tab_len(char **str)
{
	int i = 0;
	for (; str[i]; i++);
	return (i);
}

int	test_sign(char const *str, int n)
{
	int i;

	i = 0;
	while (str[i] != '\0') {
		if (str[i] == '-')
			n = -n;
		i++;
	}
	return (n);
}

int	my_getnbr_neg(char *str)
{
	int i = 0;
	int n = 0;

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			n = n + (str[i] - 48);
			n = n * 10;
		}
		else if (str[i] != '-' && str[i] != '+')
			break;
		i++;
	}
	n = n / 10;
	n = test_sign(str, n);
	if (n > 2147483647 && n < -2147483647)
		n = 0;
	return (n);
}
