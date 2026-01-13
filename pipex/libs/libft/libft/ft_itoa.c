/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:35:43 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/16 16:55:14 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isize(int n)
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

static int	isneg(int n)
{
	if (n >= 0)
		return (0);
	return (1);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	long	num;
	char	*ptr;

	size = isize(n);
	i = 0;
	num = (long)n;
	if (n < 0)
		num = -(long)n;
	ptr = (char *)malloc((size + 1 + isneg(n)) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < size)
	{
		ptr[((size + isneg(n)) - i) - 1] = '0' + (num % 10);
		num = num / 10;
		i++;
	}
	if (isneg(n) == 1)
		ptr[0] = '-';
	ptr[i + isneg(n)] = '\0';
	return (ptr);
}
