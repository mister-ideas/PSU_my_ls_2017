##
## EPITECH PROJECT, 2017
## Library
## File description:
## Makefile
##

SRC=		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_getnbr.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-W -Wall -fno-builtin

CPPFLAG=	-I include

NAME=		libmy.a


all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mkdir -p ../my
		mv $(NAME) ../my/

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f ../my/$(NAME)

re:		fclean all

.PHONY:		all clean fclean re
