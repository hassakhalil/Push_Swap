/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:28:07 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/13 00:41:43 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_markup(int x, int y, int markup_mode)
{
	if (!markup_mode)
	{
		if (x < y)
			return (1);
		return (0);
	}
	if (x + 1 == y)
		return (1);
	return (0);
}

int	markup_head_helper(t_list *tmp, int size, int markup_mode)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	i = 0;
	tmp1 = tmp;
	tmp2 = tmp;
	while (size)
	{
		if (check_markup(tmp1->content, tmp2->next->content, markup_mode))
		{
			i++;
			tmp2 = tmp2->next;
			tmp1 = tmp2;
		}
		else
			tmp2 = tmp2->next;
		size--;
	}
	return (i);
}

t_list	*markup_head(t_list *stack_a, int size, int markup_mode)
{
	t_list	*markup_head;
	t_list	*tmp;
	int		flag;
	int		j;
	int		i;

	tmp = stack_a;
	j = 0;
	flag = 0;
	while (tmp != stack_a || !flag)
	{
		flag = 1;
		i = markup_head_helper(tmp, size, markup_mode);
		if (j < i)
		{
			j = i;
			markup_head = tmp;
		}
		tmp = tmp->next;
	}
	return (markup_head);
}

void	markup(t_list **stack_a, int markup_mode)
{
	t_list	*markup_h;
	int 	size;

	size = ft_lstsize(*stack_a);
	markup_h = markup_head(*stack_a, size, markup_mode);
	(*stack_a) = markup_h;
	(*stack_a)->markup = 1;
	while (size - 1)
	{
		if (check_markup(markup_h->content, (*stack_a)->next->content, markup_mode))
		{
			(*stack_a) = (*stack_a)->next;
			(*stack_a)->markup = 1;
			markup_h = (*stack_a);
		}
		else
		{
			(*stack_a) = (*stack_a)->next;
			(*stack_a)->markup = 0;
		}
		size--;
	}
	if (!markup_mode)
		(*stack_a) = (*stack_a)->next;
}
