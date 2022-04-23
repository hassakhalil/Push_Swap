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
		if (execution_h1(stack_a, instruction[i]))
			;
		else if (!ft_strncmp("pb", instruction[i], 3))
		{
			if (!(j + 1 < n))
				return (1);
			push(stack_a, stack_b);
			j++;
		}
		else if (execution_h2(stack_a, stack_b, instruction[i], &j))
			return (1);
		i++;
	}
	return (j);
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

char	**checker_h(void)
{
	char	*si;
	char	*s;
	char	**instructions;

	si = get_next_line(0);
	if (!si)
		return (0);
	if (!ft_strncmp(si, "Error\n", 5))
	{
		write(2, "Error\n", 6);
		return (0);
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
	return (instructions);
}

void	checker(t_list *stack_a)
{
	char	**instructions;
	t_list	*stack_b;
	int		n;

	instructions = checker_h();
	if (!instructions)
		return ;
	stack_b = 0;
	n = execution(instructions, &stack_a, &stack_b);
	if (n == -1)
		write(2, "Error\n", 6);
	else if (n == 1 || verification(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_table(instructions);
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
