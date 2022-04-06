/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/06 20:47:10 by hkhalil          ###   ########.fr       */
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
	//t_list	*tmp;


	error = check_for_error(argc, argv);
    if (argc > 2 && !error)
	{
		stack_b = NULL;
		markup_mode = 0;
		stack_a = indexation(argc, argv);
		a_to_b(&stack_a, &stack_b, markup_mode);
		if (stack_b)
			b_to_a(&stack_a, &stack_b);
		while (stack_a->content)
		{
			rotate(&stack_a, 0);
			write(1, "ra\n", 3);
		}
		//test
		/*tmp = stack_a;
		while (tmp->next != stack_a)
		{
			printf("%d\n", tmp->content);
			tmp = tmp->next;
		}
			printf("%d\n", tmp->content);*/
		/*perfome algo with both markups compare and dispay better result*/
	}
    return (0);
}
