/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:16:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/12 20:38:17 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_list **stack_a, t_list **stack_b, int markup_mode)
{
	if (!markup_mode)
		greater_than(stack_a);
	else
		by_index(stack_a);
	/*while (*ft_strchr(markup, 48))
	{
		if (check_swap(*stack_a, markup_mode))
		{
			swap(*stack_a);
			if (!markup_mode)
				greater_than(stack_a);
			else
				by_index(stack_a);
		}
		else if ((*stack_a)->markup == 0)
			push(stack_a, stack_b);
		else
			rotate(stack_a, 0);
		return ;
	}*/
} 
