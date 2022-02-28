/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:20:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/28 20:47:06 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_x, t_list **stack_y)
{
	t_list	*tmp;
	t_list	*head;
	t_list	*node;

	ft_lstadd_front(stack_y, ft_lstnew(*stack_x)->content));
	tmp = *stack_x;
	head = *stack_x;
	node = *stack_x;
	ft_lstlast(tmp)->next = head->next;
	stack_x = &(head->next);
	node->next = 0;
	free(node);
}
