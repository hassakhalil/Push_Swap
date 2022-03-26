/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:07:40 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/26 16:02:52 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_mover(t_list **stack_a, t_list **stack_b, int markup_mode)
{
	t_list	*tmp;
	int		index;

	tmp = *stack_b;
	index = tmp->content;
	while (tmp->next != *stack_b)
	{
		//calculate how many moves
		//from current positionv to top of b
		//+ preparing the right element for receiving from b
	}
	//do the same steps for the last element
	return (index);
}

void	move(t_list **stack_a, t_list **stack_b, int index)
{
	//move b until the chosen one
	while ((*stack_b)->content != index)
		(*stack_b) = (*stack_b)->next;
	//move a until the right index
	while (index > (*stack_a)->next->content)
		(*stack_a) = (*stack_a)->next;
}

void	b_to_a(t_list **stack_a, t_list **stack_b, int markup_mode)
{

	while (ft_lstsize(*stack_b))
	{
		choose_mover(stack_a, stack_b, markup_mode);
		move(stack_a, stack_b, index);
		push(stack_b, stack_a, markup_mode);
	}
}
