/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:45:06 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/29 12:45:06 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>


char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char	*ft_strdup(char const *str);
char    *ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif