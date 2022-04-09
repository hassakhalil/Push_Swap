/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:07:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/09 02:09:19 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_stack_a(t_list **stack_a, int l)
{
	t_list	*head;
	int		index;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	head = *stack_a;
	index = 2147483647;
	while (head != *stack_a || !flag)
	{
		flag = 1;
		if (head->content > l && head->content < index)
		{
			index = head->content;
			i = 1;
		}
		head = head->next;
	}
	if (i == 0)
	{
		head = *stack_a;
		while (head->next != *stack_a)
		{
			if (head->content > head->next->content)
				index = head->next->content;
			head = head->next;
		}
		if (head->content > head->next->content)
			index = head->next->content;
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
	int		x;

	flag = 0;
	k = 2147483647;
	tmp = *stack_b;
	index = tmp->content;
	while (tmp != *stack_b || !flag)
	{
		flag = 1;
		i = 0;
		stack = tmp;
		x = direction(stack, (*stack_b)->content);
		while (stack != *stack_b)
		{
			i++;
			rotate(&stack, x);
		}
		l = prepare_stack_a(stack_a, tmp->content);
		stack = *stack_a;
		x = direction(stack, l);
		while (stack->content != l)
		{
			i++;
			rotate(&stack, x);
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
	int	x;
	int	y;

	l = prepare_stack_a(stack_a, index);
	x = direction(*stack_b, index);
	y = direction(*stack_a, l);
	if (x == y)
	{
		while (((*stack_b)->content != index) && ((*stack_a)->content != l))
		{
			rotate(stack_a, x);
			rotate(stack_b, x);
			if (x == 0)
				write(1, "rr\n", 3);
			else
				write(1, "rrr\n", 4);
		}
	}
	while ((*stack_b)->content != index)
	{
		rotate(stack_b, x);
		if (x == 0)
			write(1, "rb\n", 3);
		else
			write(1, "rrb\n", 4);
	}
	while ((*stack_a)->content != l)
	{
		rotate(stack_a, y);
		if (y == 0)
			write(1, "ra\n", 3);
		else
			write(1, "rra\n", 4);
	}
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
		write(1, "pa\n", 3);
		n--;
	}
}
