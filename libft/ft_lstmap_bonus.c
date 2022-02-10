/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:22:43 by hkhalil           #+#    #+#             */
/*   Updated: 2022/02/07 17:34:15 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*head;
	t_list	*first;

	if (!lst)
		return (0);
	head = ft_lstnew(f(lst->content));
	lst = lst->next;
	first = lst;
	while (first)
	{
		new = ft_lstnew(f(first->content));
		if (!new)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, new);
		first = first->next;
	}
	return (head);
}
