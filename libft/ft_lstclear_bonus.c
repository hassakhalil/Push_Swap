/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:16:30 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/07 17:30:50 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*tmp;
	t_list	*head;

	if (!lst)
		return ;
	head = *lst;
	while (head->next != *lst)
	{
		tmp = head->next;
		ft_lstdelone(head, del);
		head = tmp;
	}
	lst = NULL;
}
