/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:20:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/01 14:35:44 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_x, t_list **stack_y)
{
	t_list	*head;
	t_list	*curr;
	t_list	*prev;
	t_list	*tmp;

	head = *stack_x;
	ft_lstadd_front(stack_y, ft_lstnew((*stack_x)->content));
	curr = head;
	prev = curr;
	head = head->next;
	ft_lstlast(prev)->next = head;
	tmp  = head;
	stack_x = &tmp;
	free(curr);
}
