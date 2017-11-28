##
## EPITECH PROJECT, 2017
## my_ls
## File description:
## Makefile
##

SRC_DIR=	.

SRC=		$(SRC_DIR)/my_ls.c		\

OBJ=		$(SRC:.c=.o)

CFLAGS=		-W -Wall -fno-builtin

CPPFLAGS=	-I include/

LFLAGS=		-L lib/my/ -l my

NAME=		my_ls

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/src
		gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		rm -f $(OBJ)
		make clean -C lib/src

fclean:		clean
		rm -f $(NAME)
		make fclean -C lib/src

re:		fclean all

.PHONY:		all clean fclean re
