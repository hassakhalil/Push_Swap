/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/26 18:33:44 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_list  *stack_a;
//	t_list	*stack_b;
    char	*greater_than_markup;
    char	*by_index_markup;
	int i = 0;

	/*preparing for soliving*/
    //indexation
    stack_a = indexation(argc, argv);

    //markup
    greater_than_markup = greater_than(stack_a, argc);
	by_index_markup = by_index(stack_a, argc);
	//testing
	//swap(stack_a);
	rotate(&stack_a, 1);
	while (argc - 1 > i)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
    /*form stack A to stack B*/

	/*from stack B to stack A*/

	/*align stack A*/
    

	/*perfome algo with both markups compare and dispay better result*/
    return (0);
}
