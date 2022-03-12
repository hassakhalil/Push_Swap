/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:15:44 by hkhalil           #+#    #+#             */
/*   Updated: 2022/03/12 22:31:58 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"
t_list  *indexation(int argc, char *argv[]);
void	markup(t_list **stack_a, int makrup_mode);
void	swap(t_list *stack);
void	push(t_list **stack_x, t_list **stack_y);
void	rotate(t_list **stack, int direction);
void	a_to_b(t_list **stack_a, t_list	**stack_b, int markup_mode);
int		check_swap(t_list *stack, int markup_mode);
#endif
