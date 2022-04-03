/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:07:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/03 21:30:34 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_stack_a(t_list **stack_a, int l)
{
	t_list	*head;
	int		index;
	int		flag;

	flag = 0;
	head = *stack_a;
	index = head->content;
	while (head != *stack_a || !flag)
	{
		flag = 1;
		if (head->content > l && head->content < index)
			index = head->content;
		head = head->next;
	}
	return (index);
}

int	choose_mover(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*stack;
	int		index;
	int		i;
	int		k;
	int		l;
	int		flag;

	flag = 0;
	k = 10000000;
	tmp = *stack_b;
	index = tmp->content;
	while (tmp != *stack_b || !flag)
	{
		flag = 1;
		i = 0;
		//you have to fixe tthis
		stack = tmp;
		while (stack != *stack_b)
		{
			i++;
			stack = stack->next;
		}

		l = prepare_stack_a(stack_a, tmp->content);
		stack = *stack_a;
		while (stack->content != l)
		{
			i++;
			stack = stack->next;
		}
		if (i < k)
		{
			k = i;
			index = tmp->content;
		}
		tmp = tmp->next;
	}
	return (index);
}

void	move(t_list **stack_a, t_list **stack_b, int index)
{
	int	l;

	while ((*stack_b)->content != index)
		(*stack_b) = (*stack_b)->next;
	l = prepare_stack_a(stack_a, index);
	while ((*stack_a)->content != l)
		(*stack_a) = (*stack_a)->next;
}

void	b_to_a(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	n;

	n = ft_lstsize(*stack_b);
	while (n)
	{
		index = choose_mover(stack_a, stack_b);
		move(stack_a, stack_b, index);
		push(stack_b, stack_a);
		n--;
	}
}
