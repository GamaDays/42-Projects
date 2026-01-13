/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:37:15 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/19 17:00:43 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	if (!d && !s)
		return (NULL);
	i = 0;
	x = (unsigned char *)d;
	y = (unsigned char *)s;
	while (i < n)
	{
		x[i] = y[i];
		i++;
	}
	d = (void *)x;
	return (d);
}
