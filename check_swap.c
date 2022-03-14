/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:51:36 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/14 23:26:17 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_swap(t_list *stack, int markup_mode)
{
	int		j;
	int		k;
	t_list	*tmp;

	j = 0;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->markup == 1)
			j++;
		tmp = tmp->next;
	}
	if (tmp->markup == 1)
		j++;
	swap(stack);
	markup(&stack, markup_mode);
	k = 0;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->markup == 1)
			k++;
		tmp = tmp->next;
	}
	if (tmp->markup == 1)
		k++;
	if (k > j)
		return (1);
	return (0);
}
