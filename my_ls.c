/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** my_ls.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void sorter(char **list, int nb)
{
	char temp[255];

	for (int j = 1; j < nb; j++) {
		if (my_strcmp(list[j - 1], list[j]) > 0) {
			my_strcpy(temp, list[j - 1]);
			my_strcpy(list[j - 1], list[j]);
			my_strcpy(list[j], temp);
		}
	}
}

int main(int ac, char **av)
{
	struct stat s;
	char **params = malloc(sizeof(char*) * ac - 1);
	int error = 0;
	int j = 0;
	int k = 0;

	for (int i = 1; i < ac; i++) {
		if (stat(av[i], &s) == -1) {
			write(2, "ls: cannot access '", 19); 
			write(2, av[i], my_strlen(av[i]));
			write(2, "': No such file or directory\n", 29);
			error = 1;
		} else {
			params[j] = malloc(sizeof(char) * 255);
			my_strcpy(params[j], av[i]);
			j++;
			k++;
		}
	}
	for (int i = 1; i < k; i++) {
		sorter(params, k);
	}
	for (int i = 0; i < k; i++) {
		my_putstr(params[i]);
		if (i < k - 1)
			my_putchar(' ');
		free(params[i]);
	}
	free(params);
	if (error == 1)
		return (84);
	else
		return (0);
}
