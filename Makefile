# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 21:49:34 by hkhalil           #+#    #+#              #
#    Updated: 2022/03/06 15:46:15 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c push_swap_utils.c indexation.c greater_than.c by_index.c swap.c push.c rotate.c a_to_b.c check_swap.c

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(LIB) $(OBJ)
	cc $(CFLAGS) -fsanitize=address $(OBJ) $(LIB) -o $(NAME)

$(LIB):
	make -C ./libft && make bonus -C ./libft

all: $(NAME)

clean:
	rm -rf $(OBJ) && make clean -C ./libft

fclean: clean
	rm -rf $(NAME) $(LIB)

re: fclean all
