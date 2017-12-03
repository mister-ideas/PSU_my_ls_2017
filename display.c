/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** display.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "my.h"
#include "my_ls.h"

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

void l_print_folder_files(char *folder)
{
	DIR *rep = NULL;
	char path[255];
	struct dirent *file;
	struct passwd *passwd;
	struct group *group;

	if (folder[my_strlen(folder) - 1] != '/')
		my_strcat(folder, "/");
	rep = opendir(folder);
	my_putstr("total");
	my_putchar('\n');
	while ((file = readdir(rep)) != NULL) {
		if (file->d_name[0] != '.') {
			my_strcpy(path, folder);
			my_strcat(path, file->d_name);
			l_display(passwd, group, path, file->d_name);
			my_putchar('\n');
		}
	}
	closedir(rep);
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

void l_flag_display(char **files, char **folders, int j, int k)
{
	struct passwd *passwd;
	struct group *group;

	for (int i = 0; i < j; i++) {
		if (files[i][0] != '$') {
			l_display(passwd, group, files[i], files[i]);
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
		l_print_folder_files(folders[i]);
		if (i < k - 1)
			my_putchar('\n');
	}
}
