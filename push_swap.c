/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/14 08:44:04 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	test(char **s)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		markup_mode;
	int		i;
	int		k;
	int		l;
	int		d;
	int		best;

	i = 0;
	k = 10000;
	while (i < 2)
	{
		stack_a = indexation(count(s), s);
		l = 0;
		markup_mode = i;
		stack_b = a_to_b(&stack_a, markup_mode, &l, 0);
		if (stack_b)
			b_to_a(&stack_a, &stack_b, &l, 0);
		d = direction(stack_a, 0);
		while (stack_a->content)
		{
			rotate(&stack_a, d);
			l++;
		}
		if (k > l)
		{
			k = l;
			best = i;
		}
		free_stack(stack_a);
		i++;
	}
	return (best);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		d;
	char	**s;
	int		l;
	
	argc++;
	s = parsing(argv);
	if (count(s) > 2 && !check_for_error(count(s), s))
	{
		stack_a = indexation(count(s), s);
		stack_b = a_to_b(&stack_a, test(s), &l, 1);
		if (stack_b)
			b_to_a(&stack_a, &stack_b, &l, 1);
		d = direction(stack_a, 0);
		while (stack_a->content)
		{
			rotate(&stack_a, d);
			if (d == 0)
				write(1, "ra\n", 3);
			else
				write(1, "rra\n", 4);
		}
		free_stack(stack_a);
	}
	free_table(s);
	return (0);
}
