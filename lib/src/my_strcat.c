/*
** EPITECH PROJECT, 2017
** Day07
** File description:
** Task02
*/

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;

	while (dest[i]) {
		i += 1;
	}
	while (src[j]) {
		dest[i] = src[j];
		i += 1;
		j += 1;
	}
	dest[i] = '\0';
	return (dest);
}
