/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:02:57 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/26 16:58:40 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isize(unsigned int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*utos(unsigned int n)
{
	int				size;
	int				i;
	unsigned long	num;
	char			*ptr;

	size = isize(n);
	i = 0;
	num = (long)n;
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < size)
	{
		ptr[(size - i) - 1] = '0' + (num % 10);
		num = num / 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
