CC = cc -Wall -Werror -Wextra
SRC = main_function.c
NAME = so_long
GNL = gnl

all:  $(NAME)
	
$(GNL):
	make -C $@

$(NAME): $(GNL)
	$(CC) $(SRC) ./gnl/get_next_line.a -o $@

clean:
	make -C $(GNL) clean
	rm -rf *.o
fclean: clean
	make -C $(GNL) fclean
	rm -rf $(NAME)
re: fclean all
