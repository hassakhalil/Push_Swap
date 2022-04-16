/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:09:42 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/14 08:31:15 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	free_stack(t_list *stack)
{
	t_list	*head;
	t_list	*tmp;
	int		flag;

	flag = 0;
	head = stack;
	while (head != stack || !flag)
	{
		flag = 1;
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_table(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s[i]);
	free(s);
}
