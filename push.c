/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:20:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/23 19:00:58 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_x, t_list **stack_y)
{
	t_list	*tmp;

	ft_lstadd_front(stack_y, ft_lstnew((*stack_x)->content));
	tmp = *stack_x;
	*stack_x = (*stack_x)->next;
	ft_lstlast(tmp)->next = *stack_x;
	free(tmp);
}
