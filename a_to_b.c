/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:16:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/14 05:33:13 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_zero(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->markup == 0)
			return (1);
		tmp = tmp->next;
	}
	if (tmp->markup == 0)
		return (1);
	return (0);
}

int	check_swap_h(t_list **stack)
{
	int		j;
	int		flag;
	t_list	*head;

	j = 0;
	flag = 0;
	head = *stack;
	while ((*stack) != head || !flag)
	{
		flag = 1;
		if ((*stack)->markup == 1)
			j++;
		(*stack) = (*stack)->next;
	}
	return (j);
}

int	check_swap(t_list **stack, int markup_mode)
{
	int		j;
	int		k;

	j = check_swap_h(stack);
	swap(stack);
	markup(stack, markup_mode);
	k = check_swap_h(stack);
	swap(stack);
	markup(stack, markup_mode);
	if (k > j)
		return (1);
	return (0);
}

t_list	*a_to_b(t_list **stack_a, int markup_mode, int *moves, int phase)
{
	int		direction;
	t_list	*stack_b;

	stack_b = 0;
	markup(stack_a, markup_mode);
	direction = 0;
	while (check_zero(*stack_a))
	{
		if (check_swap(stack_a, markup_mode))
		{
			swap(stack_a);
			if (phase == 1)
				write(1, "sa\n", 3);
			else
				(*moves)++;
			markup(stack_a, markup_mode);
		}
		else if ((*stack_a)->markup == 0)
		{
			push(stack_a, &stack_b);
			if (check_zero(*stack_a))
				direction = fastest_push(*stack_a);
			if (phase == 1)
				write(1, "pb\n", 3);
			else
				(*moves)++;
		}
		else
		{
			rotate(stack_a, direction);
			if (phase == 1)
			{
				if (direction == 0)
					write(1, "ra\n", 3);
				else
					write(1, "rra\n", 4);
			}
			else
				(*moves)++;
		}
	}
	return (stack_b);
}
