/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	for (;;) {
		dest[i] = src[i];
		if (src[i] == '\0') {
			return (dest);
		}
		i += 1;
	}
}
