/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:28:07 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/18 17:45:29 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*greater_than(t_list *stack_a, int argc)
{
	t_list	*markup_head;
	t_list	*head;
	t_list	*tmp;
	t_list	*hassan;
	int		i;
	int		j;
	int		n;
	int		*markup;

	markup = malloc(sizeof(int *) * (argc - 1));
	markup_head = stack_a;
	j = 0;
	while (markup_head->next != stack_a)
	{
		i = 0;
		n = argc - 1;
		head = markup_head;
		while (n)
		{
			if (head->content < head->next->content)
				i++;
			head = head->next;
			n--;
		}
		if (j < i)
		{
			j = i;
			tmp = markup_head;
		}
		markup_head = markup_head->next;
	}
	markup_head = tmp;
	n = argc - 1;
	markup[argc - 1 - ft_lstsize(tmp)] = 1;
	while (n)
	{
		if (markup_head->content < markup_head->next->content)
			markup[argc - ft_lstsize(tmp)] = 1;
		else
			markup[argc - ft_lstsize(tmp)] = 0;
		markup_head = markup_head->next;
		n--;
	}
	return (markup);
}
