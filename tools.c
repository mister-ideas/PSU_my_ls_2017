/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** tools.c
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

void check_flags(char *flags, char **files, char **folders, int j, int k)
{
	if (flags[0] == '$')
		no_flag_display(files, folders, j, k);
	else if (flags[0] == 'l')
		l_flag_display(files, folders, j, k);
}

void free_list(char **list, int nb)
{
	for (int i = 0; i < nb; i++)
		free(list[i]);
	free(list);
}

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

void l_display(struct passwd *passwd, struct group *group, char *path, char *file)
{
	struct stat s;
	char *mtime;

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
	my_putstr(file);
}
