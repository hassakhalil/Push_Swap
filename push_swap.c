/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:20:26 by hkhalil           #+#    #+#             */
/*   Updated: 2021/12/22 16:52:33 by hkhalil          ###   ########.fr       */
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
    t_list  *list = indexation(argc, argv);
    while (list)
    {
        printf("%d\n", list->content);
        list = list->next;
    }
    return (0);
}
