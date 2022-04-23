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
#include "checker_bonus.h"

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

int	execution_h1(t_list **stack_a, char *instruction)
{
	if (!ft_strncmp("sa", instruction, 3))
	{
		swap(stack_a);
		return (1);
	}
	else if (!ft_strncmp("ra", instruction, 3))
	{
		rotate(stack_a, 0);
		return (1);
	}
	else if (!ft_strncmp("rra", instruction, 4))
	{
		rotate(stack_a, 1);
		return (1);
	}
	return (0);
}

int	execution_h2(t_list **stack_a, t_list **stack_b, char *instruction, int *j)
{
	if (!(*j))
		return (1);
	else if (!ft_strncmp("pa", instruction, 3))
	{
		push(stack_b, stack_a);
		(*j)--;
	}
	else if (!ft_strncmp("sb", instruction, 3))
		swap(stack_b);
	else if (!ft_strncmp("rb", instruction, 3))
		rotate(stack_b, 0);
	else if (!ft_strncmp("rrb", instruction, 4))
		rotate(stack_b, 1);
	else if (!ft_strncmp("ss", instruction, 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp("rr", instruction, 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp("rrr", instruction, 4))
		rr(stack_a, stack_b, 1);
	return (0);
}
