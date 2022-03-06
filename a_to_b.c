/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:16:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/06 15:53:33 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_list **stack_a, t_list **stack_b)
{
	char	*greater_than_markup;
	char	*by_index_markup;

	greater_than_markup = greater_than(*stack_a, /*size*/);
	by_index_markup = by_index(stack_a, /*size*/);
	while (/*stack_a has "false"*/)
	{
		if (check_swap(stack_a))
		{
			swap(*stack_a);
			/*update markup*/
		}
		else if (/*stack_a head == "false" */)
			push(stack_a, stack_b);
		else
			rotate(stack_a, 0);
	}
} 
