/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:16:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/15 18:05:19 by hkhalil          ###   ########.fr       */
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
void	a_to_b(t_list **stack_a, t_list **stack_b, int markup_mode)
{
	markup(stack_a, markup_mode);
	//
	t_list	*tmp;
	tmp = *stack_a;
	while (tmp->next != *stack_a)
	{
		printf("%d-----%d-----%d\n", tmp->index, tmp->content, tmp->markup);
		tmp = tmp->next;
	}
		printf("%d-----%d-----%d\n", tmp->index, tmp->content, tmp->markup);
	return ;
	while (check_zero(*stack_a))
	{
		if (check_swap(*stack_a, markup_mode))
		{
			swap(*stack_a);
			markup(stack_a, markup_mode);
		}
		else if ((*stack_a)->markup == 0)
			push(stack_a, stack_b);
		else
			rotate(stack_a, 0);
	}
} 
