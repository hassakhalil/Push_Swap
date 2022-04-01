/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:07:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/01 01:25:01 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_mover(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*head;
	int		index;
	int		i;
	int		k;

	i = 0;
	tmp = *stack_b;
	index = tmp->content;
	while (tmp->next != *stack_b)
	{
		i = 0;
		head = tmp;
		while (head->next != (*stack_b))
		{
			i++;
			head = head->next;
		}
		head = *stack_a;
		while (head->content < tmp->content)
		{
			i++;
			head = head->next;
		}
		if (i > k)
		{
			k = i;
			index = tmp->content;
		}
		tmp = tmp->next;
	}
	i = 0;
	head = tmp;
	while (head->next != (*stack_b))
	{
		i++;
		head = head->next;
	}
	head = *stack_a;
	while (head->content < tmp->content)
	{
		i++;
		head = head->next;
	}
	if (i > k)
	{
		k = i;
		index = tmp->content;
	}
	return (index);
}

void	move(t_list **stack_a, t_list **stack_b, int index)
{
	while ((*stack_b)->content != index)
		(*stack_b) = (*stack_b)->next;
	while (index > (*stack_a)->next->content)
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
