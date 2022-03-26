/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/23 21:24:28 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap_h(t_list	**stack, int markup_mode)
{
	t_list	*head;
	int		i;

	i = 0;
	head = *stack;
	while ((*stack)->next != head)
	{
		if ((*stack)->markup == 1)
			i++;
		(*stack) = (*stack)->next;
	}
	printf("hellooooo\n");
	if ((*stack)->markup == 1)
		i++;
	(*stack) = (*stack)->next;
	swap(stack);
	markup(stack, markup_mode);
	return (i);
}

int	check_swap(t_list **stack, int markup_mode)
{
	int		j;
	int		k;

	j = check_swap_h(stack, markup_mode);
	k = check_swap_h(stack, markup_mode);
	if (k > j)
		return (1);
	return (0);
}
