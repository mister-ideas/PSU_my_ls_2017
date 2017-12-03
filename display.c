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

void print_rights(struct stat s)
{
	((s.st_mode & S_IFDIR) != 0) ? my_putchar('d') : my_putchar('-');
	((s.st_mode & S_IRUSR) != 0) ? my_putchar('r') : my_putchar('-');
	((s.st_mode & S_IWUSR) != 0) ? my_putchar('w') : my_putchar('-');
	((s.st_mode & S_IXUSR) != 0) ? my_putchar('x') : my_putchar('-');
	((s.st_mode & S_IRGRP) != 0) ? my_putchar('r') : my_putchar('-');
	((s.st_mode & S_IWGRP) != 0) ? my_putchar('w') : my_putchar('-');
	((s.st_mode & S_IXGRP) != 0) ? my_putchar('x') : my_putchar('-');
	((s.st_mode & S_IROTH) != 0) ? my_putchar('r') : my_putchar('-');
	((s.st_mode & S_IWOTH) != 0) ? my_putchar('w') : my_putchar('-');
	((s.st_mode & S_IXOTH) != 0) ? my_putchar('x') : my_putchar('-');
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

void l_print_folder_files(char *folder)
{
	DIR *rep = NULL;
	struct dirent *file;
	struct stat s;
	struct passwd *passwd;
	struct group *group;
	char path[255];
	char *mtime;

	if (folder[my_strlen(folder) - 1] != '/')
		my_strcat(folder, "/");
	rep = opendir(folder);
	my_putstr("total");
	my_putchar('\n');
	while ((file = readdir(rep)) != NULL) {
		if (file->d_name[0] != '.') {
			my_strcpy(path, folder);
			my_strcat(path, file->d_name);
			stat(path, &s);
			print_rights(s);
			my_putstr(". ");
			my_put_nbr(s.st_nlink);
			my_putchar(' ');
			passwd = getpwuid(s.st_uid);
			my_putstr(passwd->pw_name);
			my_putchar(' ');
			group = getgrgid(s.st_gid);
			my_putstr(group->gr_name);
			my_putchar(' ');
			my_put_nbr(s.st_size);
			my_putchar(' ');
			mtime = ctime(&(s.st_mtim.tv_sec));
			write(1, mtime + 4, 12);
			my_putchar(' ');
			my_putstr(file->d_name);
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
	struct stat s;
	struct passwd *passwd;
	struct group *group;
	char *mtime;

	for (int i = 0; i < j; i++) {
		if (files[i][0] != '$') {
			stat(files[i], &s);
			print_rights(s);
			my_putstr(". ");
			my_put_nbr(s.st_nlink);
			my_putchar(' ');
			passwd = getpwuid(s.st_uid);
			my_putstr(passwd->pw_name);
			my_putchar(' ');
			group = getgrgid(s.st_gid);
			my_putstr(group->gr_name);
			my_putchar(' ');
			my_put_nbr(s.st_size);
			my_putchar(' ');
			mtime = ctime(&(s.st_mtim.tv_sec));
			write(1, mtime + 4, 12);
			my_putchar(' ');
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
		l_print_folder_files(folders[i]);
		if (i < k - 1)
			my_putchar('\n');
	}
}
