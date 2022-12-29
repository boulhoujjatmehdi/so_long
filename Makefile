CC = cc -Wall -Werror -Wextra
SRC = main_function.c graphical.c
NAME = so_long
GNL = gnl
LBT = libft
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(SRC) 
	make -C libft
	make -C gnl
	$(CC) $(SRC) ./gnl/get_next_line.a $(MLX)  -o $@

clean:
	make -C $(GNL) clean
	make -C $(LBT) clean
	rm -rf *.o

fclean: clean
	make -C $(GNL) fclean
	make -C $(LBT) fclean
	rm -rf $(NAME)

re: fclean all
