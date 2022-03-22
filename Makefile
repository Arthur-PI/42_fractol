SRC_DIR	= src/

DEP_DIR	= includes/

OBJ_DIR	= bin/

NAME	= fractol

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -I$(DEP_DIR)

SRCS	= fractol.c \

OBJS	= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all:	$(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean re

.PHONY:	all clean fclean re
