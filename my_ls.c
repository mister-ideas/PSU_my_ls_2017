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

void print_folder_files(char *folder)
{
	DIR *rep = NULL;
	struct dirent *file_read;

	rep = opendir(folder);
	while ((file_read = readdir(rep)) != NULL) {
		if (file_read->d_name[0] != '.') {
			my_putstr(file_read->d_name);
			my_putchar('\n');
		}
	}
	closedir(rep);
}

void no_param_display(char **files, char **folders, int j, int k)
{
	for (int i = 0; i < j; i++) {
		my_putstr(files[i]);
		my_putchar('\n');
	}
	if (j > 0 && k > 0)
		my_putchar('\n');
	for (int i = 0; i < k; i++) {
		if (j > 0 || k > 1) {
			my_putstr(folders[i]);
			my_putstr(":\n");
		}
		print_folder_files(folders[i]);
		if (i < k - 1)
			my_putchar('\n');
	}

}

void free_list(char **list, int nb)
{
	for (int i = 0; i < nb; i++)
		free(list[i]);
	free(list);
}

int check_not_found(int ac, char **av)
{
	struct stat s;

	for (int i = 1; i < ac; i++) {
		if (opendir(av[i]) == NULL && stat(av[i], &s) == -1) {
			write(2, "ls: cannot access '", 19);
			write(2, av[i], my_strlen(av[i]));
			write(2, "': No such file or directory\n", 29);
			av[i] = ".";
			return (1);
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	char **files = malloc(sizeof(char*) * (ac - 1));
	char **folders = malloc(sizeof(char*) * (ac - 1));
	int error = 0;
	int j = 0;
	int k = 0;

	if (ac == 1) {
		print_folder_files(".");
		return (0);
	}
	if (check_not_found(ac, av) == 1)
		error = 1;
	for (int i = 1; i < ac; i++) {
		if (opendir(av[i]) == NULL) {
			files[j] = malloc(sizeof(char) * my_strlen(av[i]) + 1);
			my_strcpy(files[j], av[i]);
			j++;
		} else {
			folders[k] = malloc(sizeof(char) * my_strlen(av[i]) + 1);
			my_strcpy(folders[k], av[i]);
			k++;
		}
	}
	no_param_display(files, folders, j, k);
	free_list(files, j);
	free_list(folders, k);
	if (error == 1)
		return (84);
	return (0);
}
