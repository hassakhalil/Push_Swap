/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:29:14 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/10 21:43:15 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_markup_head_helper(t_list *tmp, int size)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;

	i = 0;
	tmp1 = tmp;
	tmp2 = tmp;
	while (size)
	{
		if (tmp1->content + 1 == tmp2->next->content)
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

t_list	*ft_markup_head(t_list *stack_a, int size)
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
		i = ft_markup_head_helper(tmp, size);
		if (j < i)
		{
			j = i;
			markup_head = tmp;
		}
		tmp = tmp->next;
	}
	return (markup_head);
}

char	*by_index(t_list *stack_a)
{
	t_list	*markup_head;
	t_list	*tmp;
	char	*markup;
	int		size;

	size = ft_lstsize(stack_a);
	markup = malloc(sizeof(char *) * (size + 1));
	markup_head = ft_markup_head(stack_a, size);
	tmp = markup_head;
	markup[size] = 0;
	markup[tmp->index] = 49;
	while (size - 1)
	{
		if (markup_head->content + 1 == tmp->next->content)
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
		size--;
	}
	return (markup);
}
