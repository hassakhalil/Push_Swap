# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 21:49:34 by hkhalil           #+#    #+#              #
#    Updated: 2022/04/12 02:18:57 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC = push_swap_utils.c push_swap_utils2.c push_swap_utils3.c get_next_line_utils.c indexation.c markup.c  swap.c push.c rotate.c a_to_b.c b_to_a.c check_for_error.c

B_SRC = ft_split.c get_next_line.c

OBJ = $(SRC:.c=.o)

B_OBJ = $(B_SRC:.c=.o)

CFLAGS = -D BUFFER_SIZE=42 -g3 -fsanitize=address -Wall -Wextra -Werror

$(NAME): $(OBJ) 
	cc $(CFLAGS) $(OBJ)  push_swap.c -o $(NAME)

all: $(NAME)

bonus: $(OBJ) $(B_OBJ)
	cc $(CFLAGS) $(OBJ) $(B_OBJ) checker_bonus.c -o $(NAME_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS) checker_bonus.o push_swap.o

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all
