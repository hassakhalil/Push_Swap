# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 21:49:34 by hkhalil           #+#    #+#              #
#    Updated: 2022/02/04 18:27:02 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c push_swap_utils.c indexation.c greater_than.c by_index.c

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
