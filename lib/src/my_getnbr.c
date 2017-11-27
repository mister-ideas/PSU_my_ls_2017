/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
	int nb = 0;
	int isneg = 1;
	int i = 0;

	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			isneg = isneg * -1;
		i += 1;
	}
	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + str[i] - '0';
			i = i + 1;
		}
		else
			return (nb * isneg);
	}
	return (nb * isneg);
}
