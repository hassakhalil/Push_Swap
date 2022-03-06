/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:20:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/06 03:26:00 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_x, t_list **stack_y)
{
	t_list	*curr;
	t_list	*prev;

	ft_lstadd_front(stack_y, ft_lstnew((*stack_x)->content));
	curr = *stack_x;
	prev = curr;
	stack_x = &((*stack_x)->next);
	ft_lstlast(prev)->next = *stack_x;
	free(curr);
}
