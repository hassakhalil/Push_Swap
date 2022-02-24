/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:29:08 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/24 15:45:36 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;
	t_list	*head;

	i = 0;
	head = lst;
	while (head->next != lst)
	{
		head = head->next;
		i++;
	}
	return (i);
}
