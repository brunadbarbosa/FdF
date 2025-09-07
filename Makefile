# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 19:55:16 by brmaria-          #+#    #+#              #
#    Updated: 2025/09/07 13:30:58 by brmaria-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME = fdf

# compiler and flags:
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -g

# Libft directory
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# minilibx library
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -Lminilibx-linux -lmlx_Linux -lX11 -lXext

# basic and additional files:
SRC =	0-main.c\
		1-parsing.c\
		2-screen.c\
		3-drawImage.c\
		4-commands.c\
		5-rotate.c\
		6-error.c
	
OBJ = $(SRC:.c=.o)

RM = rm -rf

# standard rule:
all: $(NAME)

# compile and create the lib:
$(NAME): $(MLX) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME) -lm
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

