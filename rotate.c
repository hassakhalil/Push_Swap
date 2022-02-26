/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:14:25 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/26 18:33:36 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, int direction)
{
	if (direction == 0)
		*stack = (*stack)->next;
	else if (direction == 1)
		*stack = ft_lstlast(*stack);
}
