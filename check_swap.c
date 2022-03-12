/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/12 16:32:33 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap(t_list *stack, int markup_mode, char *markup)
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
		markup = greater_than(stack);
	else
		markup = by_index(stack);
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
