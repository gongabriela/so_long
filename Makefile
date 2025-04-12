# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 16:53:51 by ggoncalv          #+#    #+#              #
#    Updated: 2025/04/12 14:05:54 by ggoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lXext -lX11 -lm -lz

SRC = main.c parse_map.c parse_map_2.c ft_free_exit.c render_map.c render_map_2.c key_handler.c update_map.c
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

# Testing target with Valgrind (maps already generated)
test: all
	@echo "🧪 Running map tests with Valgrind..."
	@mkdir -p valgrind_logs
	@echo "📁 Log directory created at: $(PWD)/valgrind_logs"
	@for map in $(MAP_DIR)/*.ber; do \
		basename=$$(basename $$map); \
		log_file="$(PWD)/valgrind_logs/$$basename.log"; \
		echo "\n🔍 Testing $$map:"; \
		echo "➡️  Running the program..."; \
		OUTPUT=$$(./$(BIN) $$map 2>&1); \
		echo "$$OUTPUT" | sed 's/^/   /'; \
		echo "🧠 Running Valgrind..."; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose \
			--log-file=$$log_file ./$(BIN) $$map > /dev/null 2>&1; \
		if grep -q "ERROR SUMMARY: 0 errors" $$log_file; then \
			echo "✅ Valgrind: PASS (no memory leaks)"; \
		else \
			echo "❌ Valgrind: FAIL (memory leaks detected)"; \
			grep "definitely lost\|indirectly lost\|possibly lost" $$log_file | sed 's/^/   /'; \
		fi; \
		rm -f $$log_file; \
	done
	@rm -rf valgrind_logs
# Norminette check for project files
norm:
norm:
	@echo "Running Norminette checks..."
	@find . -type f \( -name "*.c" -o -name "*.h" \) ! -path "./mlx/*" > .normfiles
	@norminette $$(cat .normfiles) || (echo "\n❌ Norminette found errors." && rm -f .normfiles && exit 1)
	@echo "\n✅ Norminette passed with no errors."
	@rm -f .normfiles

clean:
	make -C ./Libft fclean
	make -C ./mlx clean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
