##
## Makefile
## 
## Made by maxime ginters
## Login   <ginter_m@epitech.eu>
## 
## Started on  Sat Oct 27 16:35:32 2012 maxime ginters
## Last update Sat Oct 27 23:45:01 2012 maxime ginters
##

NAME	=	colle3

SRC	=	main.c		\
		what_is_this_glue.c \
		my_memset.c \
		my_putstr.c \
		my_str_to_wordtab.c \
		colles.c \
		colle_searcher.c \
		my_strlen.c \
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	=	 -ansi

LDFLAGS =	-lm

all	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
