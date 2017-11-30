/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** my_ls.h
*/

#ifndef MY_LS_H_
#define MY_LS_H_

void my_ls(int ac, char **av, char **files, char **folders);
void free_list(char **list, int nb);
void no_flag_display(char **files, char **folders, int j, int k);
void print_folder_files(char *folder);

int check_not_found(int ac, char **av);

#endif
