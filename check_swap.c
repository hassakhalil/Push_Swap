/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/01 01:16:20 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap(t_list **stack, int markup_mode)
{
	int		j = 0;
	int		k = 0;
	t_list	*head;

	head = *stack;
	while ((*stack)->next != head)
	{
		if ((*stack)->markup ==1)
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
		if ((*stack)->markup ==1)
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
