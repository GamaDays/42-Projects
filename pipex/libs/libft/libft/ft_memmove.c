/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:50:42 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/16 17:22:40 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	size_t	i;
	char	*x;
	char	*y;

	if (!d && !s)
		return (NULL);
	i = 0;
	x = (char *)d;
	y = (char *)s;
	if (s > d)
	{
		while (i < n)
		{
			x[i] = y[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			x[n] = y[n];
		}
	}
	return (d);
}
