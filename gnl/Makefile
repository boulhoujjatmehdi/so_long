NAME = get_next_line.a
OBJ = get_next_line.o get_next_line_utils.o
CCW = gcc -Wall -Wextra -Werror 


%.o:%.c
	$(CCW) -c $<

all: $(NAME)

$(NAME):$(OBJ)
	ar rsc $@ $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all