/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/12 20:33:42 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap(t_list *stack, int markup_mode)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (markup[i])
	{
		if (markup[i] == '1')
			j++;
		i++;
	}
	swap(stack);
	if (!markup_mode)
		greater_than(stack);
	else
		by_index(stack);
	i = 0;
	k = 0;
	while (markup[i])
	{
		if (markup[i] == '1')
			k++;
		i++;
	}
	if (k > j)
		return (1);
	return (0);
}
