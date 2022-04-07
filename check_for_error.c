/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:47:34 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/07 23:00:29 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *argv)
{
	int	j;

	j = 0;
	if (argv[j] == '-' || argv[j] == '+')
		j++;
	while (argv[j])
	{
		if (!ft_isdigit(argv[j]))
			return (1);
		j++;
	}
	return (0);
}

int	out_of_range(char *number)
{
	if (ft_atoi(number) >  2147483647|| ft_atoi(number) < -2147483648)
		return (1);
	return (0);
}

int	is_duplicate(char * argv[], int i, char *number)
{
	i--;
	while (i)
	{
		if (ft_atoi(number) == ft_atoi(argv[i]))
			return (1);
		i--;
	}
	return (0);
}

int	check_for_error(int	argc, char *argv[])
{
	int	i;

	i = 1;
	while (argc > i)
	{
		if (is_number(argv[i]) || out_of_range(argv[i]) || is_duplicate(argv, i, argv[i]))
		{
			write(2,"Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}
