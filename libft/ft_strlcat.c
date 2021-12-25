/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:57:59 by hkhalil           #+#    #+#             */
/*   Updated: 2021/11/14 21:59:17 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	if (!dest && !size)
		return (ft_strlen(src));
	x = ft_strlen(dest);
	if (size <= x)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && (x + i) < (size - 1))
	{
		dest[x + i] = src[i];
		i++;
	}
	dest[x + i] = 0;
	return (x + ft_strlen(src));
}
