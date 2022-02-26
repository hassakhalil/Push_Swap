/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:28:07 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/26 14:59:49 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_markup_head_helper(t_list *tmp, int argc)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	i = 0;
	tmp1 = tmp;
	tmp2 = tmp;
	while (argc - 1)
	{
		if (tmp1->content < tmp2->next->content)
		{
			i++;
			tmp2 = tmp2->next;
			tmp1 = tmp2;
		}
		else
			tmp2 = tmp2->next;
		argc--;
	}
	return (i);
}

t_list	*choose_markup_head(t_list *stack_a, int argc)
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
		i = choose_markup_head_helper(tmp, argc);
		if (j < i)
		{
			j = i;
			markup_head = tmp;
		}
		tmp = tmp->next;
	}
	return (markup_head);
}

char	*greater_than(t_list *stack_a, int argc)
{
	t_list	*markup_head;
	t_list	*tmp;
	char	*markup;

	markup = malloc(sizeof(char *) * argc);
	markup_head = choose_markup_head(stack_a, argc);
	tmp = markup_head;
	markup[argc - 1] = 0;
	markup[tmp->index] = 49;
	while (argc - 2)
	{
		if (markup_head->content < tmp->next->content)
		{
			markup[tmp->next->index] = 49;
			tmp = tmp->next;
			markup_head = tmp;
		}
		else
		{
			markup[tmp->next->index] = 48;
			tmp = tmp->next;
		}
		argc--;
	}
	return (markup);
}
