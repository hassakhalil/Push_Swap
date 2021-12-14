NAME = push_swap

SRC = push_swap.c push_swap_utils.c

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(LIB) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)
$(LIB):
	make -C ./libft && make bonus -C ./libft
all: $(NAME)

clean:
	rm -rf $(OBJ) && make clean -C ./libft

fclean: clean
	rm -rf $(NAME) $(LIB)

re: fclean all
