/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater_than.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:28:07 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/23 17:40:55 by hkhalil          ###   ########.fr       */
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
	while (markup_head->next != stack_a)
	{
		i = 0;
		n = argc - 1;
		head1 = markup_head;
		head2 = markup_head;
		while (n)
		{
			//printf("head1 = %d || head2 = %d\n", head1->content, head2->next->content);
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
		printf("%d\n", i);
		markup_head = markup_head->next;
	}
	markup_head = tmp;
	n = argc - 1;
	markup[ft_lstsize(stack_a) - ft_lstsize(tmp) + 1] = 1;
	while (n)
	{
		if (markup_head->content < markup_head->next->content)
			markup[ft_lstsize(stack_a) - ft_lstsize(tmp) + 1] = 1;
		else
			markup[ft_lstsize(stack_a) - ft_lstsize(tmp) + 1] = 0;
		markup_head = markup_head->next;
		n--;
	}
	printf("-----------------------\n");
	return (markup);
}
