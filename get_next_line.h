/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:52:35 by hkhalil           #+#    #+#             */
/*   Updated: 2022/04/12 23:45:20 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
#endif
