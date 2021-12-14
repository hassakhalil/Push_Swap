/*  ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:16:05 by hkhalil           #+#    #+#             */
/*   Updated: 2021/12/14 04:43:26 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list  *indexation(int argc, char *argv[])
{
    int     i;
    int     j;
    int     tmp;
    t_list  *index_list;
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
        i++;
    }
    //debug
   /* i = 0;
    while (i < argc - 3)
    {
        printf("-------%d--------\n", numbers[i]);
        i++;
    }*/
    i = 0;
    while (i < argc - 1)
    {
        j = 1;
        while(argv[j])
        {
            if (numbers[i] == ft_atoi(argv[j]))
            {
                 ft_lstadd_back(&index_list,ft_lstnew(j));
                printf("---%d---\n", j);
                 break;
            }
            j++;
        }
        i++;
    }
    printf("success3\n");
    free(numbers);
    return (index_list);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
    //int i = 0;
    t_list  *list = indexation(argc, argv);
    while (list)
    {
        printf("%d\n", list->content);
        list = list->next;
    }
    return (0);
}
