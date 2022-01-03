/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2022/01/03 18:51:44 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list  *indexation(int argc, char *argv[])
{
    int     i;
    int     j;
    int     tmp;
    t_list  *index_list = NULL;
    int     *numbers;

    numbers = malloc(sizeof(int *) * (argc - 1));
    i  = 0;
    while (i < argc - 1)
    {
        numbers[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    i = 0;
    while (i < argc - 2)
    {
        if (numbers[i] > numbers[i + 1])
        {
            tmp = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i + 1] = tmp;
            i = 0;
        }
        else
            i++;
    }
    j = 1;
    while (argv[j])
    {
        i = 0;
        while (i < argc - 1)
        {
            if (ft_atoi(argv[j]) == numbers[i])
            {
                ft_lstadd_back(&index_list, ft_lstnew(i));
                break;
            }
            i++;
        }
        j++;
    }
    free(numbers);
    return (index_list);
}

#include <stdio.h>

int main(int argc, char *argv[])
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
}
