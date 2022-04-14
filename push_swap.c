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

int	main(int argc, char *argv[])
{
    t_list	*stack_a;
	t_list	*stack_b;
	int		markup_mode;
	int		error;
	int		d;
	char	**s;
	int		i;
	int		l;
	int		k = 10000;
	int		best;



	argc++;
	s = parsing(argv);
	error = check_for_error(count(s), s);
    if (count(s) > 2 && !error)
	{
		i = 0;
		while (i < 2)
		{
			stack_b = NULL;
			stack_a = indexation(count(s), s);
			l = 0;
			markup_mode = i;
			a_to_b(&stack_a, &stack_b, markup_mode, &l, 0);
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
		stack_b = NULL;
		stack_a = indexation(count(s), s);
		a_to_b(&stack_a, &stack_b, best, &l, 1);
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
