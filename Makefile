# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apigeon <apigeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 11:49:34 by apigeon           #+#    #+#              #
#    Updated: 2022/03/22 16:48:29 by apigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
IFLAGS	= -L $(LIBFT) -L $(MLX) -L $(HEADER)

### EXECUTABLE ###
NAME	= fractol

### INCLUDES ###
LIBFT	= libft
OBJ_DIR	= bin
HEADER	= incl
SRC_DIR	= src
MLX		= libmlx

### SOURCE FILES ###
SRCS	= main.c \

### OBJECTS ###
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###
all:	$(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(NOC)"
	@make -C $(LIBFT)
	@make -C $(MLX)

$(NAME):	lib $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT) -L$(MLX) -lft -lmlx $(OBJS) -o $(NAME)
	@echo "$(GREEN)Project successfully compiled$(NOC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Supressing libraries files$(NOC)"
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@echo "$(GREEN)Supressing object files$(NOC)"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make fclean -C $(LIBFT)
	@echo "$(GREEN)Supressing program file$(NOC)"
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
