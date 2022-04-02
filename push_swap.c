/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/02 01:28:25 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
    t_list	*stack_a;
	t_list	*stack_b;
	int		markup_mode = 0;
	t_list	*tmp;

    stack_a = indexation(argc, argv);
	a_to_b(&stack_a, &stack_b, markup_mode);
	b_to_a(&stack_a, &stack_b);
	tmp = stack_a;
	while (tmp->next != stack_a)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->content);
	/*align stack A*/ 
	/*perfome algo with both markups compare and dispay better result*/
    return (0);
}
