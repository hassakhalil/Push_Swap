/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/13 23:12:44 by hkhalil          ###   ########.fr       */
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


	argc++;
	s = parsing(argv);
	error = check_for_error(count(s), s);
    if (count(s) > 2 && !error)
	{
		stack_b = NULL;
		markup_mode = 0;
		stack_a = indexation(count(s), s);
		a_to_b(&stack_a, &stack_b, markup_mode);
		if (stack_b)
			b_to_a(&stack_a, &stack_b);
		d = direction(stack_a, 0);
		while (stack_a->content)
		{
			rotate(&stack_a, d);
			if (d == 0)
				write(1, "ra\n", 3);
			else
				write(1, "rra\n", 4);
		}
		/*perfome algo with both markups compare and dispay better result*/
		
		//free a
	}
    return (0);
}
