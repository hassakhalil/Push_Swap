/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/04 17:52:02 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*int main(int argc, char *argv[])
{
    t_list  *list;
    char    *greater_than_list;
    char    *by_index_list;

    //indexation
    list = indexation(argc, argv);
    //markup
    greater_than_list = greater_than_markup(list);
    by_index_list = by_index_markup(list);
    if (ft_strlen(greater_than_list) > ft_strlen(by_index_list))
        print_list(by_index_list);
    else
        print_list(greater_than_list);
    //free everything and return
    free(list);
    free(greater_than_list);
    free(by_index_list);
    return (0);
}*/

int main(int argc, char *argv[])
{
	t_list	*stack_a = indexation(argc, argv);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}
