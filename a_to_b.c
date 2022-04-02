/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:16:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/02 02:10:19 by hkhalil          ###   ########.fr       */
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
	t_list	*head;

	j = 0;
	k = 0;
	head = *stack;
	while ((*stack)->next != head)
	{
		if ((*stack)->markup == 1)
			j++;
		(*stack) = (*stack)->next;
	}
	if ((*stack)->markup == 1)
		j++;
	(*stack) = (*stack)->next;
	swap(stack);
	markup(stack, markup_mode);
	while ((*stack)->next != head)
	{
		if ((*stack)->markup == 1)
			k++;
		(*stack) = (*stack)->next;
	}
	if ((*stack)->markup == 1)
		k++;
	swap(stack);
	markup(stack, markup_mode);
	(*stack) = (*stack)->next;
	if (k > j)
		return (1);
	return (0);
}

void	a_to_b(t_list **stack_a, t_list **stack_b, int markup_mode)
{
	markup(stack_a, markup_mode);
	while (check_zero(*stack_a))
	{
		if (check_swap(stack_a, markup_mode))
		{
			swap(stack_a);
			markup(stack_a, markup_mode);
		}
		else if ((*stack_a)->markup == 0)
			push(stack_a, stack_b);
		else
			rotate(stack_a, 0);
	}
}
