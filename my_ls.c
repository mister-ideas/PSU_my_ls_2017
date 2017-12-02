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
#include "my.h"
#include "my_ls.h"

int check_not_found(int ac, char **av)
{
	DIR *rep = NULL;
	struct stat s;
	int error = 0;

	for (int i = 1; i < ac; i++) {
		rep = opendir(av[i]);
		if (rep == NULL && stat(av[i], &s) == -1 && av[i][0] != '$') {
			write(2, "ls: cannot access '", 19);
			write(2, av[i], my_strlen(av[i]));
			write(2, "': No such file or directory\n", 29);
			av[i] = "$";
			error = 1;
		}
		closedir(rep);
	}
	if (error == 1)
		return (1);
	return (0);
}

void get_flags(int ac, char **av, char *flags)
{
	for (int i = 1; i < ac; i++) {
		if (av[i][0] == '-') {
			for (int j = 0; j < my_strlen(av[i]); j++)
				flags[j] = av[i][j + 1];
			av[i] = "$";
		}
	}
}

void my_ls(int ac, char **av, char **files, char **folders, char *flags)
{
	DIR *rep = NULL;
	int j = 0;
	int k = 0;
	int m = 0;

	for (int i = 1; i < ac; i++) {
		rep = opendir(av[i]);
		if (rep == NULL) {
			files[j] = malloc(sizeof(char) * my_strlen(av[i]) +1);
			my_strcpy(files[j], av[i]);
			m++;
			if (av[i][0] != '$')
				j++;
		} else {
			folders[k] = malloc(sizeof(char) * my_strlen(av[i]) +1);
			my_strcpy(folders[k], av[i]);
			k++;
		}
		closedir(rep);
	}
	check_flags(flags, files, folders, j, k);
	free_list(files, m);
	free_list(folders, k);
}

int main(int ac, char **av)
{
	char **files = malloc(sizeof(char*) * (ac - 1));
	char **folders = malloc(sizeof(char*) * (ac - 1));
	char *flags = malloc(sizeof(char) * 6);
	int error = 0;

	if (files == NULL || folders == NULL)
		return (84);
	flags[0] = '$';
	get_flags(ac, av, flags);
	if (ac == 1) {
		print_folder_files(".");
		return (0);
	}
	if (ac == 2) {
		if (flags[0] == 'l') {
			l_print_folder_files(".");
			return (0);
		}
	}
	if (check_not_found(ac, av) == 1)
		error = 1;
	my_ls(ac, av, files, folders, flags);
	free(flags);
	if (error == 1)
		return (84);
	return (0);
}
