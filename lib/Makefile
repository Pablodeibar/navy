##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME		=		libmy.a

NAME_TEST	=		unit_tests

SRC			=		my/format_modulo.c					\
					my/my_len.c							\
					my/my_printf.c						\
					my/my_putchar.c						\
					my/my_putnbr_base.c					\
					my/my_put_nbr.c						\
					my/my_putstr.c						\
					my/my_revstr.c						\
					my/my_strlen.c						\
					my/my_getnbr.c						\
					my/get_num.c						\
					my/my_swap.c						\
					my/int_char.c						\
					my/my_strcmp.c						\
					my/my_str_isnum.c

SRC_TESTS	=		$(SRC)								\
					tests_lib/tests_lib.c

OBJ			=		$(SRC:.c=.o)

FLAGS		=	--coverage -lcriterion -I./lib

CC			=	gcc

all: 		$(NAME)

$(NAME): 	$(OBJ)
		ar rc $(NAME) $(OBJ)

tests_run:	clean
			$(CC) -o $(NAME_TEST) $(SRC_TESTS) $(FLAGS)
			./$(NAME_TEST)

clean:
		rm -f $(OBJ)
		rm -f *.gc*

fclean:		clean
		rm -f $(NAME)
		rm -f $(NAME_TEST)

re: 		fclean all

.PHONY: all clean fclean re $(NAME)