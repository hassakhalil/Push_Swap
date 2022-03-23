/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:41:28 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/23 18:54:28 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int		tmp;

	tmp = (*stack)->next->content;
	(*stack)->next->content = (*stack)->content;
	(*stack)->content = tmp;
}
