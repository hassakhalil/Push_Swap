/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 06:26:18 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/18 06:26:41 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_h(int phase, int *moves, int x, int move)
{
	if (phase == 1)
	{
		if (move == 1)
		{
			if (x == 0)
				write(1, "rr\n", 3);
			else
				write(1, "rrr\n", 4);
		}
		else if (move == 2)
		{
			if (x == 0)
				write(1, "rb\n", 3);
			else
				write(1, "rrb\n", 4);
		}
		else
		{
			if (x == 0)
				write(1, "ra\n", 3);
			else
				write(1, "rra\n", 4);
		}
	}
	(*moves)++;
}

void	rr(t_list **stack_a, t_list **stack_b, int x)
{
	rotate(stack_a, x);
	rotate(stack_b, x);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	move(t_list **stack_a, t_list **stack_b, int *moves, int phase)
{
	int	l;
	int	x;
	int	y;
	int	index;

	index = choose_mover(stack_a, stack_b);
	l = prepare_stack_a(stack_a, index);
	x = direction(*stack_b, index);
	y = direction(*stack_a, l);
	while (x == y
		&& ((*stack_b)->content != index) && ((*stack_a)->content != l))
	{
		rr(stack_a, stack_b, x);
		move_h(phase, moves, x, 1);
	}
	while ((*stack_b)->content != index)
	{
		rotate(stack_b, x);
		move_h(phase, moves, x, 2);
	}
	while ((*stack_a)->content != l)
	{
		rotate(stack_a, y);
		move_h(phase, moves, y, 3);
	}
}
