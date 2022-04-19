/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:28:43 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/17 02:20:26 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	execution(char **instruction, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = ft_lstsize(*stack_a);
	if (check_words(instruction))
		return (-1);
	while (instruction[i])
	{
		if (!ft_strncmp("sa", instruction[i], ft_strlen(instruction[i])))
			swap(stack_a);
		else if (j && !ft_strncmp("sb", instruction[i], ft_strlen(instruction[i])))
			swap(stack_b);
		else if ((j + 1 < n) &&!ft_strncmp("pb", instruction[i], ft_strlen(instruction[i])))
		{
			push(stack_a, stack_b);
			j++;
		}
		else if (!ft_strncmp("ra", instruction[i], ft_strlen(instruction[i])))
			rotate(stack_a, 0);
		else if (!ft_strncmp("rra", instruction[i], ft_strlen(instruction[i])))
			rotate(stack_a, 1);
		else if (j && !ft_strncmp("rb", instruction[i], ft_strlen(instruction[i])))
			rotate(stack_b, 0);
		else if (j && !ft_strncmp("rrb", instruction[i], ft_strlen(instruction[i])))
			rotate(stack_b, 1);
		else if (j && !ft_strncmp("pa", instruction[i], ft_strlen(instruction[i])))
		{
			push(stack_b, stack_a);
			j--;
		}
		else if (j && !ft_strncmp("ss", instruction[i], ft_strlen(instruction[i])))
			ss(stack_a, stack_b);
		else if (j && !ft_strncmp("rr", instruction[i], ft_strlen(instruction[i])))
			rr(stack_a, stack_b, 0);
		else if (j && !ft_strncmp("rrr", instruction[i], ft_strlen(instruction[i])))
			rr(stack_a, stack_b, 1);
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
	char	*s;
	char	*si;
	char	**instructions;
	t_list	*stack_b;

	si = get_next_line(0);
	if (!si)
		return ;
	if (!ft_strncmp(si, "Error\n", 5))
	{
		write(2, "Error\n", 6);
		return ;
	}
	s = ft_strdup("\n");
	while (si)
	{
		s = ft_strjoin(s, si);
		free(si);
		si = get_next_line(0);
	}
	instructions = ft_split(s, '\n');
	free(s);
	stack_b = 0;
	if (execution(instructions, &stack_a, &stack_b))
	{
		if (execution(instructions, &stack_a, &stack_b) == -1)
			write(2, "Error\n", 6);
		else
			write(1, "KO\n", 3);
		free_table(instructions);
		return ;
	}
	if (verification(stack_a))
	{
		write(1, "KO\n", 3);
		return ;
	}
	write(1, "OK\n", 3);
	free_stack(stack_a);
	return ;
}

int	main(int argc, char *argv[])
{
	int		error;
	t_list	*stack_a;
	char	**s;

	argc++;
	s = parsing(argc, argv);
	error = check_for_error(count(s), s);
	if (count(s) > 2 && !error)
	{
		stack_a = indexation(count(s), s);
		checker(stack_a);
	}
	free_table(s);
}
