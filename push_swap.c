/*  ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:16:05 by hkhalil           #+#    #+#             */
/*   Updated: 2021/12/14 01:49:38 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *indexation(int argc, char *argv[])
{
    int     i;
    int     j;
    int     tmp;
    int     argc_holder;
    t_list  *index_list;
    int     *numbers;

    argc_holder = argc - 1;
    numbers = malloc(sizeof(int) * argc_holder);
    i  = 0;
    while (argc_holder)
    {
        numbers[i] = ft_atoi(argv[i + 1]);
        i++;
        argc_holder--;
    }
    i = 0;
    while (i < argc - 2)
    {
        if (numbers[i] < numbers[i + 1])
        {
            tmp = numbers[i];
            numbers[i] = numbers[i + 1];
            numbers[i] = tmp;
            i = 0;
        }
        i++;
    }
    i = 0;
    while (i < argc - 1)
    {
        j = 1;
        while(argv[j])
        {
            if (numbers[i] == ft_atoi(argv[j]))
            {
                 ft_lstadd_back(&index_list,ft_lstnew(&j));
                break;
            }
            j++;
        }
        i++;
    }
    return (index_list);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
   // int i = 0;
    t_list  *list = indexation(argc, argv);
    while (list)
    {
        printf("%d/n", *((int *)(list->content)));
        list = list->next;
    }
    return (0);
}

