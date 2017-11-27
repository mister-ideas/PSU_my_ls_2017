/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "../../include/my.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
