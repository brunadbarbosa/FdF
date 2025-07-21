# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 19:55:16 by brmaria-          #+#    #+#              #
#    Updated: 2025/07/21 19:34:35 by brmaria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = fdf

# compiler and flags:
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft

# Libft directory
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

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
$(NAME): $(MLX) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "Let's build this FdF! Done!"

# compile .o:
%.o: %.c fdf.h
	@$(CC) $(CFLAGS) -Ilibft -c $< -o $@
	@echo "Compiling $<..."

$(MLX):
	@echo "Making MiniLibX..."
	@make -C $(MLX_DIR)

$(LIBFT):
	@echo "Making Libft..."
	@make -C $(LIBFT_DIR)
	
# clean files:
clean:
	@$(RM) $(OBJ)
	@echo "Off with these files!"

# clean everything, .o and libft.a:
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "Binary gone!"

# recompile all:
re: fclean all

.PHONY: all re clean fclean

