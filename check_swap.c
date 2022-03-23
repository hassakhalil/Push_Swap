/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/23 20:27:57 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap(t_list **stack, int markup_mode)
{
	int		j;
	int		k;
	t_list	*head;

	j = 0;
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
	k = 0;
	while ((*stack)->next != head)
	{
		if ((*stack)->markup == 1)
			k++;
		(*stack) = (*stack)->next;
	}
	if ((*stack)->markup == 1)
		k++;
	(*stack) = (*stack)->next;
	swap(stack);
	if (k > j)
		return (1);
	return (0);
}
