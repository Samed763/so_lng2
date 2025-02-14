NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLXDIR = ./minilibx-linux
MLX = -L$(MLXDIR) -lmlx -lXext -lX11
GNLDIR = ./get_next_line

SRC = $(GNLDIR)/get_next_line.c $(GNLDIR)/get_next_line_utils.c main.c set_values.c \
	utils_one.c gecici.c utils_two.c utils_three.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLX)
	rm -rf $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
