/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:28:07 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/24 16:27:23 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*greater_than(t_list *stack_a, int argc)
{
	t_list	*markup_head;
	t_list	*head1;
	t_list	*head2;
	t_list	*tmp;
	int		i;
	int		j;
	int		n;
	int		*markup;

	markup = malloc(sizeof(int *) * (argc - 1));
	markup_head = stack_a;
	j = 0;
	while (markup_head->next != stack_a && markup)
	{
		i = 0;
		n = argc - 1;
		head1 = markup_head;
		head2 = markup_head;
		while (n)
		{
			if (head1->content < head2->next->content)
			{
				i++;
				head2 = head2->next;
				head1 = head2;
			}
			else
				head2 = head2->next;
			n--;
		}
		if (j < i)
		{
			j = i;
			tmp = markup_head;
		}
		markup_head = markup_head->next;
	}
	i = 0;
	n = argc - 1;
	head1 = markup_head;
	head2 = markup_head;
	while (n)
	{
		if (head1->content < head2->next->content)
		{
			i++;
			head2 = head2->next;
			head1 = head2;
		}
		else
			head2 = head2->next;
		n--;
	}
	if (j < i)
	{
		j = i;
		tmp = markup_head;
	}
	n = argc - 1;
	markup[tmp->next->index] = 6;
	head2 = tmp;
	while (n)
	{
		if (tmp->content < head2->next->content)
		{
			markup[head2->next->index] = 1;
			head2 = head2->next;
			tmp = head2;
		}
		else
		{
			markup[head2->next->index] = 0;
			head2 = head2->next;
		}
		n--;
	}
	return (markup);
}
