/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** my_ls.c
*/

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

int check_error(char **av, char **files, int i, int j)
{
	struct stat s;

	if (stat(av[i], &s) == -1) {
		write(2, "ls: cannot access '", 19);
		write(2, av[i], my_strlen(av[i]));
		write(2, "': No such file or directory\n", 29);
		return (1);
	} else {
		files[j] = malloc(sizeof(char) * 255);
		my_strcpy(files[j], av[i]);
	}
	return (0);
}

int main(int ac, char **av)
{
	char **files = malloc(sizeof(char*) * ac - 1);
	char **folders = malloc(sizeof(char*) * ac - 1);
	struct dirent *file_read = NULL;
	DIR* rep = NULL;
	int error = 0;
	int j = 0;
	int k = 0;

	for (int i = 1; i < ac; i++) {
		if (opendir(av[i]) == NULL) {
			if (check_error(av, files, i, j) == 1)
				error = 1;
			else
				j++;
		} else {
			folders[k] = malloc(sizeof(char) * 255);
			my_strcpy(folders[k], av[i]);
			k++;
		}
	}
	for (int i = 0; i < j; i++) {
		my_putstr(files[i]);
		if (i < j - 1)
			my_putchar('\n');
		free(files[i]);
	}
	for (int i = 0; i < k; i++) {
		my_putstr("\n\n");
		my_putstr(folders[i]);
		my_putstr(":\n");
		rep = opendir(folders[i]);
	        if ((file_read = readdir(rep)) != NULL)
			my_putstr(file_read->d_name);
		if (i < k - 1)
			my_putchar(' ');
		free(folders[i]);
	}
	free(files);
	free(folders);
	if (error == 1)
		return (84);
	return (0);
}
