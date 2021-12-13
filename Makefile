NAME = push_swap

SRC = push_swap.c push_swap_utils.c 
LIB= ./libft/libft.a

OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror

$(NAME): lib 
	cc $(SRC) $(LIB) -o $(NAME) 

lib:
	 make -C ./libft && make bonus -C ./libft

clean_lib:
	 make clean -C ./libft

fclean_lib:
	make fclean -C ./libft

re_lib:
	make re -C ./libft

all: $(NAME)


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
