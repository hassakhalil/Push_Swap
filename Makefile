NAME = push_swap

SRC = push_swap.c push_swap_utils.c 

OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $<
	ar -rc $(NAME) $@


clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
