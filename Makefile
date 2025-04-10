# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:53:51 by ggoncalv          #+#    #+#              #
#    Updated: 2025/04/11 10:44:30 by ggoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lXext -lX11 -lm -lz

SRC = main.c parse_map.c parse_map_2.c ft_free_exit.c tests.c render_map.c render_map_2.c key_handler.c update_map.c
OBJ = $(SRC:.c=.o)

LIBFT = ./Libft/libft.a
MLX = ./mlx/libmlx.a

MAP_DIR = maps
BIN = ./$(NAME)

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
	$(CC) $(CFLAGS) -g $(SRC) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)
	gdb --tui $(NAME)

norm:
	norminette main.c parse_map.c parse_map_2.c ft_free_exit.c tests.c render_map.c render_map_2.c key_handler.c update_map.c
clean:
	make -C ./Libft fclean
	make -C ./mlx clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all maps
	@echo "Running map tests..."
	@for map in $(MAP_DIR)/*.ber; do \
		echo -n "Testing $$map... "; \
		timeout 3s ./$(BIN) $$map > /dev/null 2>&1; \
		if [ $$? -eq 0 ]; then \
			echo "✅ PASS"; \
		else \
			echo "❌ FAIL"; \
		fi; \
	done
