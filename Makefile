##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##


SRC			=	source/navy.c					\
				source/infos.c					\
				source/player_one.c				\
				source/player_two.c				\
				source/apply_pos.c				\
				source/cut_pos.c				\
				source/open_pos.c				\
				source/split_string.c			\
				source/verif_pos.c				\
				source/verif_line.c				\
				source/game_play.c				\

SRC_MAIN	=	main.c

SRC_TESTS	=	

OBJ			=	$(SRC_MAIN:.c=.o)						\
				$(SRC:.c=.o)

CC			=	gcc

FLAGS		=	--coverage -lcriterion

CFLAGS		=	-Wall -Wextra -I./include

LIB			=	-L./lib -lmy

NAME		=	navy

NAME_TEST	=	unit_tests

all:		lib $(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
			rm -f $(OBJ)
			rm -f *.gc*
			rm -f *~

fclean:			clean
			rm -f $(NAME)
			rm -f $(NAME_TEST)
			make -C lib/ fclean

tests_run:		lib
			$(CC) -o $(NAME_TEST) $(SRC_TESTS) $(LIB) $(FLAGS) $(CFLAGS)
			./$(NAME_TEST)

lib:
			make -C lib/

re:				fclean all

.PHONY: clean lib
