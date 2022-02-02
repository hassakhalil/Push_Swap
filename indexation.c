/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:58:12 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/02 20:52:52 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*indexation(int argc, char *argv[])
{
	int		i;
	int		j;
	int		tmp;
	t_list	*index_list;
	int		*numbers;

	index_list = NULL;
	numbers = malloc(sizeof(int *) * (argc - 1));
	i = 0;
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
				break ;
			}
			i++;
		}
		j++;
	}
	free(numbers);
	return (index_list);
}
