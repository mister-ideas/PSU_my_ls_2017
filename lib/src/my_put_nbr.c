/*
** EPITECH PROJECT, 2017
** Library
** File description:
** my_put_nbr.c
*/

#include "my.h"

int my_put_nbr(int nb)
{
	if (nb < -2147483647)
		my_putstr("-2147483648");
	else if (nb < 0) {
		nb *= -1;
		my_putchar('-');
		if (nb > 10)
			my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	} else if (nb >= 10) {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	} else
		my_putchar(nb + '0');
	return (0);
}
