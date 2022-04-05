/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/05 22:56:20 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
    t_list	*stack_a;
	t_list	*stack_b = NULL;
	int		markup_mode = 0;
	t_list	*tmp;

    stack_a = indexation(argc, argv);
	a_to_b(&stack_a, &stack_b, markup_mode);
	if (stack_b)
		b_to_a(&stack_a, &stack_b);
	//align stack a
	while (stack_a->content)
		stack_a = stack_a->next;
	tmp = stack_a;
	while (tmp->next != stack_a)
	{
		printf("%d -------- %d -------- %d\n", tmp->content, tmp->index, tmp->markup);
		tmp = tmp->next;
	}
		printf("%d  ------- %d -------- %d\n", tmp->content, tmp->index, tmp->markup);
	/*perfome algo with both markups compare and dispay better result*/
    return (0);
}
