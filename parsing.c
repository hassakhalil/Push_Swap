/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 05:37:34 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/13 22:44:15 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_of_args(char *s)
{
	int	i = 0;
	int	n = 0;
	int flag = 0;

	while (s[i])
	{
		while (s[i] && s[i] != ' ')
		{
			if (flag == 0)
			{
				flag = 1;
				n++;
			}
			i++;
		}
		if (s[i])
		{
			i++;
			flag = 0;
		}
	}
	return (n);
}

char	**parsing(char *argv[])
{
	char	**s;
	char	**si;
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	n = 0;


	while (argv[i])
	{
		n = n + count_of_args(argv[i]);
		i++;
	}
	s = malloc(sizeof(char *) * (n + 1));
	i = 0;
	k = 0;
	while (argv[i])
	{
		si = ft_split(argv[i], ' ');
		j = 0;
		while (si[j])
		{
			s[k] = ft_strdup(si[j]);
			free(si[j]);
			k++;
			j++;
		}
		i++;
	}
	s[k] = NULL;
	return (s);
}
