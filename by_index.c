/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:29:14 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/05 20:54:16 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*by_index(t_list *stack_a, int argc)
{
	t_list	*head;
	int		i;
	int		j;
	int		*markup;
	t_list		*markup_head;

	markup = malloc(sizeof(int *) * (argc - 1));
	head = stack_a;
	markup_head = stack_a;
	i = 0;
	j = 0;
	while (markup_head)
	{
		while (argc - 1)
		{
			if (!stack_a)
				stack_a = head;
			if (stack_a->content == (stack_a->next)->content + 1)
			{
				markup[argc - 1 - ft_lstsize(stack_a)] = 1;
				i++;
			}
			else
				markup[argc - 1 - ft_lstsize(stack_a)] = 0;
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
