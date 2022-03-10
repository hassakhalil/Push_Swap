/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/10 22:00:23 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_list  *stack_a;
	t_list	*stack_b;
	int		markup_mode = 0;

    //indexation
    stack_a = indexation(argc, argv);
    /*form stack A to stack B*/
	a_to_b(&stack_a, &stack_b, markup_mode);
	/*from stack B to stack A*/

	/*align stack A*/
    

	/*perfome algo with both markups compare and dispay better result*/
    return (0);
}
