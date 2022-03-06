NAME = libft.a

SRC = ft_atoi.c ft_isdigit.c

BSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $<
	ar -rc $(NAME) $@

bonus: $(BOBJ)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
