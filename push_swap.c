/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/26 15:08:55 by hkhalil          ###   ########.fr       */
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
	while (greater_than_markup[i])
	{
		printf("%c\n", greater_than_markup[i]);
		i++;
	}
	printf("--------------------------\n");
	i = 0;
	while (by_index_markup[i])
	{
		printf("%c\n", by_index_markup[i]);
		i++;
	}
    /*form stack A to stack B*/

	/*from stack B to stack A*/

	/*align stack A*/
    

	/*perfome algo with both markups compare and dispay better result*/
    return (0);
}
