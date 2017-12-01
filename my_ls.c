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

	for (int i = 1; i < ac; i++) {
		rep = opendir(av[i]);
		if (rep == NULL && stat(av[i], &s) == -1) {
			write(2, "ls: cannot access '", 19);
			write(2, av[i], my_strlen(av[i]));
			write(2, "': No such file or directory\n", 29);
			av[i] = ".";
			return (1);
		}
		closedir(rep);
	}
	return (0);
}

void free_list(char **list, int nb)
{
	for (int i = 0; i < nb; i++)
		free(list[i]);
	free(list);
}

void my_ls(int ac, char **av, char **files, char **folders)
{
	DIR *rep = NULL;
	int j = 0;
	int k = 0;

	for (int i = 1; i < ac; i++) {
		rep = opendir(av[i]);
		if (rep == NULL) {
			files[j] = malloc(sizeof(char) * my_strlen(av[i]) +1);
			my_strcpy(files[j], av[i]);
			j++;	
		} else {
			folders[k] = malloc(sizeof(char) * my_strlen(av[i]) +1);
			my_strcpy(folders[k], av[i]);
			k++;
		}
		closedir(rep);
	}
	no_flag_display(files, folders, j, k);
	free_list(files, j);
	free_list(folders, k);
}

int main(int ac, char **av)
{
	char **files = malloc(sizeof(char*) * (ac - 1));
	char **folders = malloc(sizeof(char*) * (ac - 1));
	int error = 0;

	if (files == NULL || folders == NULL)
		return (84);
	if (ac == 1) {
		print_folder_files(".");
		return (0);
	}
	
	if (check_not_found(ac, av) == 1)
		error = 1;
	my_ls(ac, av, files, folders);
	if (error == 1)
		return (84);
	return (0);
}
