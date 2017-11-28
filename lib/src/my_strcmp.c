/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_strcmp.c
*/

int my_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i += 1;
	return (s1[i] - s2[i]);
}
