/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:43:57 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/13 22:02:10 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "push_swap.h"
# include "get_next_line.h"

void    checker(t_list *stack_a);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
void    *ft_memcpy(void *dest, const void *src, size_t n);
int     check_words(char **instructions);

#endif
