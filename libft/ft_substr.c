/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:44:53 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/08 17:46:28 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start || !len)
		sub = malloc(1);
	else if (ft_strlen(s) <= len + start)
		sub = malloc(ft_strlen(s) - start + 1);
	else
		sub = malloc(len + 1);
	if (!sub)
		return (0);
	i = 0;
	if (ft_strlen(s) > start)
	{
		while (s[i + start] && len > 0)
		{
			sub[i] = s[start + i];
			i++;
			len--;
		}
	}
	sub[i] = 0;
	return ((char *)sub);
}
