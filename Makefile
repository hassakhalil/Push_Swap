# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 21:49:34 by hkhalil           #+#    #+#              #
#    Updated: 2022/04/08 01:25:03 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC = push_swap_utils.c push_swap_utils2.c push_swap_utils3.c indexation.c markup.c  swap.c push.c rotate.c a_to_b.c b_to_a.c check_for_error.c

SRC_BONUS = ft_split.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -D BUFFER_SIZE=42 -g3 -fsanitize=address -Wall -Wextra -Werror

$(NAME): $(OBJ) $(OBJ_BONUS)
	cc $(CFLAGS) $(OBJ) $(OBJ_BONUS) push_swap.c -o $(NAME)

all: $(NAME)

bonus:
	cc $(CFLAGS) checker.c $(OBJ_BONUS) $(OBJ) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS) checker.o push_swap.o

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
