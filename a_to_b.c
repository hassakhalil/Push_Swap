/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:16:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/09 00:58:49 by hkhalil          ###   ########.fr       */
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

int	check_swap(t_list **stack, int markup_mode)
{
	int		j;
	int		k;
	int		flag;
	t_list	*head;

	j = 0;
	k = 0;
	flag = 0;
	head = *stack;
	while ((*stack) != head || !flag)
	{
		flag = 1;
		if ((*stack)->markup == 1)
			j++;
		(*stack) = (*stack)->next;
	}
	flag = 0;
	swap(stack);
	markup(stack, markup_mode);
	while ((*stack) != head || !flag)
	{
		flag = 1;
		if ((*stack)->markup == 1)
			k++;
		(*stack) = (*stack)->next;
	}
	swap(stack);
	markup(stack, markup_mode);
	if (k > j)
		return (1);
	return (0);
}

void	a_to_b(t_list **stack_a, t_list **stack_b, int markup_mode)
{
	int	direction;

	markup(stack_a, markup_mode);
	direction = 0;
	while (check_zero(*stack_a))
	{
		if (check_swap(stack_a, markup_mode))
		{
			swap(stack_a);
			write(1, "sa\n", 3);
			markup(stack_a, markup_mode);
		}
		if ((*stack_a)->markup == 0)
		{
			push(stack_a, stack_b);
			//if (check_zero(*stack_a))
			//	direction = fastest_push(*stack_a);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(stack_a, direction);
			write(1, "ra\n", 3);
		}
	}
}
