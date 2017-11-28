/*
1;4804;0c** EPITECH PROJECT, 2017
** my_ls
** File description:
** my_ls.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	struct stat s;
	char **params = malloc(sizeof(char*) * ac - 1);
	char temp[255];
	int error = 0;
	int j = 0;
	int k = 0;

	for (int i = 1; i < ac; i++) {
		if (stat(av[i], &s) == -1) {
			write(2, "ls: cannot access '", 19); 
			write(2, av[i], my_strlen(av[i]));
			write(2, "': No such file or directory\n", 29);
			error = 1;
		} else {
			params[j] = malloc(sizeof(char) * my_strlen(av[i]) + 1);
			my_strcpy(params[j], av[i]);
			j++;
			k++;
		}
	}
	for (int i = 1; i < k; i++) {
		for (int j = 1; j < k; j++) {
			if (my_strcmp(params[j - 1], params[j]) > 0) {
				my_strcpy(temp, params[j - 1]);
				my_strcpy(params[j - 1], params[j]);
				my_strcpy(params[j], temp);
			}
		}
	}
	for (int i = 0; i < k; i++) {
		my_putstr(params[i]);
		if (i < k - 1)
			my_putchar(' ');
		free(params[i]);
	}
	free(params);
	if (error == 1)
		return (84);
	else
		return (0);
}
