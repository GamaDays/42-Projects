/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:03:40 by tlaukat           #+#    #+#             */
/*   Updated: 2024/04/08 19:24:55 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <strings.h>
# ifndef FT_PRINTF_FD
#  define FT_PRINTF_FD 0
# endif

int		ft_printf(const char *s, ...);
char	*ctos(int n, int *r);
char	*stos(char *str);
char	*utos(unsigned int n);
char	*htos(unsigned int n, char type);
char	*ptos(unsigned long long ptr);

#endif