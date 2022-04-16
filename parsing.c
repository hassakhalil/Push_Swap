/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 05:37:34 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/14 05:38:25 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_of_args(char *s)
{
	int	i;
	int	n;
	int	flag;

	flag = 0;
	i = 0;
	n = 0;
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

char	**total_of_args(char *argv[])
{
	char	**s;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (argv[i])
	{
		n = n + count_of_args(argv[i]);
		i++;
	}
	s = malloc(sizeof(char *) * (n + 1));
	return (s);
}

char	*copy(char *x)
{
	char	*y;

	y = ft_strdup(x);
	free(x);
	return (y);
}

char	**parsing(char *argv[])
{
	char	**s;
	char	**si;
	int		i;
	int		j;
	int		n;

	s = total_of_args(argv);
	if (!s)
		return (0);
	i = 0;
	n = 0;
	while (argv[i])
	{
		si = ft_split(argv[i], ' ');
		j = 0;
		while (si[j])
		{
			s[n] = copy(si[j]);
			n++;
			j++;
		}
		i++;
	}
	s[n] = NULL;
	return (s);
}
