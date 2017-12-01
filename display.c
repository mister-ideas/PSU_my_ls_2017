/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** display.c
*/

#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

void free_list(char **list, int nb)
{
	for (int i = 0; i < nb; i++)
		free(list[i]);
	free(list);
}

void print_folder_files(char *folder)
{
	DIR *rep = NULL;
	struct dirent *file;

	rep = opendir(folder);
	while ((file = readdir(rep)) != NULL) {
		if (file->d_name[0] != '.') {
			my_putstr(file->d_name);
			my_putchar('\n');
		}
	}
	closedir(rep);
}

void check_flags(char *flags, char **files, char **folders, int j, int k)
{
	if (flags[0])
		no_flag_display(files, folders, j, k);
}

void no_flag_display(char **files, char **folders, int j, int k)
{
	for (int i = 0; i < j; i++) {
		if (files[i][0] != '$') {
			my_putstr(files[i]);
			my_putchar('\n');
		}
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
