# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 19:55:16 by brmaria-          #+#    #+#              #
#    Updated: 2025/07/10 20:53:37 by brmaria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = fdf

# compiler and flags:
CC = cc
CFLAGS = -Wall -Wextra -Werror

# minilibx library
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# basic and additional files:
SRC =	0-main.c\

		
OBJ = $(SRC:.c=.o)

RM = rm -rf

# standard rule:
all: $(NAME)

# compile and create the lib:
$(NAME): $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "Let's build this FdF! Done!"

# compile .o:
%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<..."

$(MLX):
	@echo "Making MiniLibX..."
	@make -C $(MLX_DIR)
	
# clean files:
clean:
	@$(RM) $(OBJ)
	@echo "Off with these files!"

# clean everything, .o and libft.a:
fclean: clean
	@$(RM) $(NAME)
	@echo "Binary gone!"

# recompile all:
re: fclean all

.PHONY: all re clean fclean

