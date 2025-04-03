# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:53:51 by ggoncalv          #+#    #+#              #
#    Updated: 2025/04/03 15:10:24 by ggoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lXext -lX11 -lm -lz

SRC = main.c parse_map.c
OBJ = $(SRC:.c=.o)

LIBFT = ./Libft/libft.a
MLX = ./mlx/libmlx.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./Libft
	make -C ./mlx
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

debug:
	make -C ./Libft
	make -C ./mlx
	$(CC) $(CFLAGS) -g $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	gdb --tui $(NAME)

clean:
	make -C ./Libft fclean
	make -C ./mlx clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
