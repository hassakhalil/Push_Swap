/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:05:34 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/10 23:14:13 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	string_size(long k, int sign)
{
	int	i;

	i = 1;
	while (k > 9)
	{
		k = k / 10;
		i++;
	}
	if (sign == -1)
		i++;
	return (i + 1);
}

int	ft_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	int		i;
	long	k;
	char	*s;

	k = n;
	k = k * ft_sign(n);
	i = string_size(k, ft_sign(n));
	s = malloc(i);
	if (!s)
		return (0);
	s[i - 1] = 0;
	while (k > 9)
	{
		s[i - 2] = (k % 10) + '0';
		k = k / 10;
		i--;
	}
	s[i - 2] = k + '0';
	if (n < 0)
		s[i - 3] = '-';
	return (s);
}
