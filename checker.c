/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:28:43 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/08 00:25:38 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execution(char **instruction, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (instruction[i])
	{
		if (!ft_strncmp("sa", instruction[i], 3))
			swap(stack_a);
		else if (!ft_strncmp("pb", instruction[i], 3))
			push(stack_a, stack_b);
		else if (!ft_strncmp("ra", instruction[i], 3))
			rotate(stack_a, 0);
		else if (!ft_strncmp("rra", instruction[i], 3))
			rotate(stack_a, 1);
		else if (!ft_strncmp("rb", instruction[i], 3))
			rotate(stack_b, 0);
		else if (!ft_strncmp("rrb", instruction[i], 3))
			rotate(stack_b, 1);
		else if (!ft_strncmp("pa", instruction[i], 3))
			push(stack_b, stack_a);
		i++;
	}
}

int	verification(t_list *stack_a)
{
	t_list	*head;

	head = stack_a;
	while (head->next != stack_a)
	{
		if (head->content > head->next->content)
			return (1);
		head = head->next;
	}
	return (0);
}

void	checker(t_list *stack_a)
{
	char	*s;
	char	*si;
	char	**instructions;
	t_list	*stack_b = 0;


	si = get_next_line(1);
	if (!ft_strncmp(si, "Error\n", 5))
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (si)
	{
		s = ft_strjoin(s, si);
		si = get_next_line(1);
	}
	instructions = ft_split(s, '\n');
	execution(instructions, &stack_a, &stack_b);
	if (verification(stack_a))
	{
		write(1, "KO\n", 3);
		return ;
	}
	write(1, "OK\n", 3);
	return ;
}
