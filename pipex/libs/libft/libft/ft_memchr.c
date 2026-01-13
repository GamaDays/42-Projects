/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:15:43 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/15 16:53:10 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*x;
	size_t			i;

	x = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(x + i) == (unsigned char)c)
		{
			return (x + i);
		}
		i++;
	}
	return (NULL);
}
