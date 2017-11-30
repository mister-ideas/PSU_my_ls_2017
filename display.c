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

void no_flag_display(char **files, char **folders, int j, int k)
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
