SRC	=	$(SRC_DIR)main.c	\
		$(SRC_DIR)parsing.c	\
		$(SRC_DIR)concat.c	\
		$(SRC_DIR)put_map.c	\
		$(SRC_DIR)move_player.c	\
		$(SRC_DIR)direction_move.c	\
		$(SRC_DIR)h_option.c

SRC_DIR	=	src/

LIB_DIR	=	lib/

INC_DIR	=	include/

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -I $(INC_DIR) -g

LDFLAGS	=	-L $(LIB_DIR) -lmy -lncurses

NAME	=	my_sokoban

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
clean:
		rm -f $(OBJ)
		make clean -C $(LIB_DIR)

fclean:		clean
		rm -f $(NAME)
		make fclean -C $(LIB_DIR)

re:		fclean all

.PHONY:	all re clean fclean
