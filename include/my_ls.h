/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** my_ls.h
*/

#ifndef MY_LS_H_
#define MY_LS_H_

void my_ls(int ac, char **av, char **files, char **folders, char *flags);
void free_list(char **list, int nb);
void l_display(struct passwd *passwd,
	       struct group *group,
	       char *path,
	       char *file);
void no_flag_display(char **files, char **folders, int j, int k);
void l_flag_display(char **files, char **folders, int j, int k);
void print_folder_files(char *folder);
void l_print_folder_files(char *folder);
void get_flags(int ac, char **av, char *flags);
void check_flags(char *flags, char **files, char **folders, int j, int k);

int check_not_found(int ac, char **av);

#endif
