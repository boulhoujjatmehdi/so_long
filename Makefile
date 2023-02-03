CC = cc -Wall -Werror -Wextra
SRC = so_long_main.c so_long_utils.c graphical.c graphical_utils.c events.c events_utils.c protect.c
NAME = so_long
GNL = gnl
PRT = printf
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(SRC) 
	make -C printf
	make -C gnl
	$(CC) $(SRC) ./printf/libftprintf.a ./gnl/get_next_line.a $(MLX)  -o $@

clean:
	make -C $(GNL) clean
	make -C $(PRT) clean
	rm -rf *.o

fclean: clean
	make -C $(GNL) fclean
	make -C $(PRT) fclean
	rm -rf $(NAME)

re: fclean all
