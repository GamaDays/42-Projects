/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:00:00 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/15 16:13:30 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	size_t	t;
	size_t	i;

	t = 0;
	i = 0;
	if (n == 0)
	{
		return ((size_t)ft_strlen(s));
	}
	while (s[t] != '\0')
	{
		t++;
	}
	while (i < n - 1 && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	if (i < n)
	{
		d[i] = '\0';
	}
	return (t);
}
