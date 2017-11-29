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

int main(int ac, char **av)
{
	char **files = malloc(sizeof(char*) * (ac - 1));
	char **folders = malloc(sizeof(char*) * (ac - 1));
	struct stat s;
	struct dirent *file_read = NULL;
	DIR* rep = NULL;
	int error = 0;
	int j = 0;
	int k = 0;

	if (ac == 1) {
		rep = opendir(".");
		while ((file_read = readdir(rep)) != NULL) {
			if (file_read->d_name[0] != '.') {
				my_putstr(file_read->d_name);
				my_putchar('\n');
			}
		}
		return (0);
	}
	for (int i = 1; i < ac; i++) {
		if (opendir(av[i]) == NULL) {
			if (stat(av[i], &s) == -1) {
				write(2, "ls: cannot access '", 19);
				write(2, av[i], my_strlen(av[i]));
				write(2, "': No such file or directory\n", 29);
				error = 1;
			} else {
				files[j] = malloc(sizeof(char) * my_strlen(av[i]) + 1);
				my_strcpy(files[j], av[i]);
				j++;
			}
		} else {
			folders[k] = malloc(sizeof(char) * my_strlen(av[i]) + 1);
			my_strcpy(folders[k], av[i]);
			k++;
		}
	}
	for (int i = 0; i < j; i++) {
		my_putstr(files[i]);
		my_putchar('\n');
		free(files[i]);
	}
	if (j > 0 && k > 0)
		my_putchar('\n');
	for (int i = 0; i < k; i++) {
		rep = opendir(folders[i]);
		if (j > 0 || k > 1) {
			my_putstr(folders[i]);
			my_putstr(":\n");
		}
		while ((file_read = readdir(rep)) != NULL) {
			if (file_read->d_name[0] != '.') {
				my_putstr(file_read->d_name);
				my_putchar('\n');
			}
		}
		closedir(rep);
		if (i < k - 1)
			my_putchar('\n');
		free(folders[i]);
	}
	free(files);
	free(folders);
	if (error == 1)
		return (84);
	return (0);
}
