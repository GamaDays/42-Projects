/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:03:05 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/26 16:57:10 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hsize(unsigned int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		c++;
	}
	return (c);
}

char	*htos(unsigned int n, char type)
{
	char	*out;
	int		i;

	i = hsize(n) - 1;
	out = (char *)malloc(i + 2);
	if (!out)
		return (NULL);
	out[i + 1] = '\0';
	while (i >= 0)
	{
		if (n % 16 > 9)
			out[i] = (n % 16) + type - 17;
		else
			out[i] = '0' + (n % 16);
		n /= 16;
		i--;
	}
	return (out);
}
