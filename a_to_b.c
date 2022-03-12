/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:16:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/12 16:33:20 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_list **stack_a, t_list **stack_b, int markup_mode)
{
	char	*markup;

	if (!markup_mode)
		markup = greater_than(*stack_a);
	else
		markup = by_index(*stack_a);
	while (ft_strchr(markup, '0'))
	{
		if (check_swap(*stack_a, markup_mode, markup))
		{
			swap(*stack_a);
			if (!markup_mode)
				markup = greater_than(*stack_a);
			else
				markup = by_index(*stack_a);
		}
		else if (markup[0] == '0')
			push(stack_a, stack_b);
		else
			rotate(stack_a, 0);
	}
} 
