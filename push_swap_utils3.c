/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:18:43 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/12 02:28:50 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] > s2[i])
			return ((unsigned char)(s1[i] - s2[i]));
		else if (s1[i] < s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	if (!s1 || !s2)
		return (0);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (0);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = 0;
	free((void *)s1);
	free((void *)s2);
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

int	direction(t_list *stack, int index)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = stack;
	while (tmp->content != index)
	{
		rotate(&tmp, 0);
		i++;
	}
	j = 0;
	tmp = stack;
	while (tmp->content != index)
	{
		rotate(&tmp, 1);
		j++;
	}
	if (i > j)
		return (1);
	return (0);
}

int	fastest_push(t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = stack;
	while (tmp->markup)
	{
		rotate(&tmp, 0);
		i++;
	}
	j = 0;
	tmp = stack;
	while (tmp->markup)
	{
		rotate(&tmp, 1);
		j++;
	}
	if (i > j)
		return (1);
	return (0);
}
