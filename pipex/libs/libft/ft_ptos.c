/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:00:08 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/26 17:25:35 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hsize(unsigned long long n)
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

char	*ptos(unsigned long long ptr)
{
	char				*out;
	int					i;
	unsigned long long	n;

	n = ptr;
	i = hsize(n) + 1;
	out = (char *)malloc(i + 2);
	if (!out)
		return (NULL);
	out[i + 1] = '\0';
	out[0] = '0';
	out[1] = 'x';
	while (i >= 2)
	{
		if (n % 16 > 9)
			out[i] = (n % 16) + 'h' - 17;
		else
			out[i] = '0' + (n % 16);
		n /= 16;
		i--;
	}
	return (out);
}
