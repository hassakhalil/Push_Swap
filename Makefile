NAME = push_swap

SRC = push_swap.c push_swap_utils.c 

OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)

lib:
	cd libft && make && make bonus 

clean_lib:
	cd libft && make clean

fclean_lib:
	cd libft && make fclean

re_lib:
	cd libft && make re

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $<
	ar -rc $(NAME) $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
