/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:15:44 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/14 04:50:28 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
typedef struct s_list
{
	int		content;
	int		index;
	int		markup;
	struct s_list	*next;
}		t_list;
long long		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_strchr(const char *s, int c);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new, int index);
t_list  *indexation(int argc, char *argv[]);
void	markup(t_list **stack_a, int makrup_mode);
void	swap(t_list **stack);
void	push(t_list **stack_x, t_list **stack_y);
void	rotate(t_list **stack, int direction);
void	a_to_b(t_list **stack_a, t_list	**stack_b, int markup_mode, int *moves, int phase);
int		check_swap(t_list **stack, int markup_mode);
void	b_to_a(t_list **stack_a, t_list **stack_b, int *moves, int phase);
int		check_for_error(int argc, char *argv[]);
int		direction(t_list *stack, int index);
int		fastest_push(t_list *stack);
char	**ft_split(char const *s, char c);
char	**parsing(char *argv[]);
int		count(char **s);
#endif
