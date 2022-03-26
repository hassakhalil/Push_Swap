/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/26 16:02:55 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_list  *stack_a;
	t_list	*stack_b;
	int		markup_mode = 0;
	t_list	*tmp;

    //indexation
    stack_a = indexation(argc, argv);
    /*form stack A to stack B*/
	a_to_b(&stack_a, &stack_b, markup_mode);
	tmp = stack_a;
	while (tmp->next != stack_a)
	{
		printf("%d------%d-----%d\n", tmp->index, tmp->content, tmp->markup);
		tmp = tmp->next;
	}
		printf("%d------%d-----%d\n", tmp->index, tmp->content, tmp->markup);
		tmp = stack_b;
	while (tmp->next != stack_b)
	{
		printf("%d++++%d++++%d\n", tmp->index, tmp->content, tmp->markup);
		tmp = tmp->next;
	}
		printf("%d++++%d++++%d\n", tmp->index, tmp->content, tmp->markup);
	/*from stack B to stack A*/

	/*align stack A*/
    

	/*perfome algo with both markups compare and dispay better result*/
    return (0);
}
