/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/13 01:02:51 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap(t_list *stack, int markup_mode)
{
	int	j;
	int	k;

	j = 0;
	//count how many elements with true j
	swap(stack);
	markup(&stack_a, markup_mode);
	k = 0;
	//count how many elements with true k
	if (k > j)
		return (1);
	return (0);
}
