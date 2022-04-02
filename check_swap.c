/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/02 01:37:16 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap(t_list **stack, int markup_mode)
{
	int		j;
	int		k;
	t_list	*head;

	head = *stack;
	j = 0;
	k = 0;
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
