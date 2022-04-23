/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:43:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/23 07:04:47 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "push_swap.h"
# include "get_next_line.h"

void	checker(t_list *stack_a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		check_words(char **instructions);
int		execution_h1(t_list **stack_a, char *instruction);
int		execution_h2(t_list **stack_a, t_list **stack_b,
			char *instruction, int *j);

#endif
