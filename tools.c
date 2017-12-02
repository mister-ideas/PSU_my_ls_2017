/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** tools.c
*/

#include <stdlib.h>
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
