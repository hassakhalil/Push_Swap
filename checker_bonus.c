/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:28:43 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/12 22:51:08 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <string.h>

int	execution(char **instruction, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int j;
	int	n;

	i = 0;
	j = 0;
	n = ft_lstsize(*stack_a);
	while (instruction[i])
	{
		if (!ft_strncmp("sa", instruction[i], 3))
			swap(stack_a);
		if (!ft_strncmp("sb", instruction[i], 3))
		{
			if (!j)
				return (1);
			swap(stack_b);
		}
		else if (!ft_strncmp("pb", instruction[i], 3))
		{
			if (j + 1 < n)
			{
				push(stack_a, stack_b);
				j++;
			}
			else
				return (1);
		}
		else if (!ft_strncmp("ra", instruction[i], 3))
			rotate(stack_a, 0);
		else if (!ft_strncmp("rra", instruction[i], 3))
			rotate(stack_a, 1);
		else if (!ft_strncmp("rb", instruction[i], 3))
		{
			if (!j)
				return (1);
			rotate(stack_b, 0);
		}
		else if (!ft_strncmp("rrb", instruction[i], 3))
		{
			if (!j)
				return (1);
			rotate(stack_b, 1);
		}
		else if (!ft_strncmp("pa", instruction[i], 3))
		{
			if (!j)
				return (1);
			push(stack_b, stack_a);
			j--;
		}
		else if (!ft_strncmp("ss", instruction[i], 3))
		{
			swap(stack_a);
			if (!j)
				return (1);
			swap(stack_b);
		}
		else if (!ft_strncmp("rr", instruction[i], 3))
		{
			if (!j)
				return (1);
			rotate(stack_a, 0);
			rotate(stack_b, 0);
		}
		else if (!ft_strncmp("rrr", instruction[i], 3))
		{
			if (!j)
				return (1);
			rotate(stack_a, 1);
			rotate(stack_b, 1);
		}
		else
			return (-1);
		i++;
	}
	if (j)
		return (1);
	return (0);
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
	char	*s = ft_strdup("\n");
	char	*si;
	char	**instructions;
	t_list	*stack_b = 0;


	si = get_next_line(0);
	if (!si)
		return ;
	if (!ft_strncmp(si, "Error\n", 5))
	{
		write(2, "Error\n", 6);
		return ;
	}
	while (si)
	{
		s = ft_strjoin(s, si);
		si = get_next_line(0);
	}
	instructions = ft_split(s, '\n');
	if(execution(instructions, &stack_a, &stack_b))
	{
		if (execution(instructions, &stack_a, &stack_b) == -1)
			write(2, "Error\n", 6);
		else
			write(1, "KO\n", 3);
		return ;
	}
	if (verification(stack_a))
	{
		write(1, "KO\n", 3);
		return ;
	}
	write(1, "OK\n", 3);
	return ;
}

int main(int argc, char	*argv[])
{
	int		error;
	t_list	*stack_a;

	error = check_for_error(argc, argv);
	if (argc > 2 && !error)
	{
		stack_a = indexation(argc, argv);
		checker(stack_a);
	}
}
