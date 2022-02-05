/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:28:07 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/05 20:39:39 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*greater_than(t_list *stack_a, int agrc)
{
	t_list	*head;
	int		i;
	int		*markup;
	int		*markup_head;

	markup = malloc(sizeof(int *) * (argc - 1));
	head = stack_a;
	markup_head = stack_a;
	i = 0;
	j = 0;
	while (markup_head)
	{
		while (arcg - 1)
		{
			if (!stack_a)
				stack_a = head;
			if (stack_a->content < (stack_a->next)->content)
			{
				markup[argc - 1 - ft_lstsize(stack_a)] = 1;
				i++;
			}
			else
				markup[argc - 1 - ft_lstsize(stack_a)] = ;
			stack_a = stack_a->next;
			argc--;
		}
		if (j < i)
		{
			j = i;
			markup_head = markup_head->next;
			stack_a = markup_head;
		}
		i = 0;
	}
	return (markup);
}
