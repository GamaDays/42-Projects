/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:51:58 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/16 17:23:31 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isize(int n)
{
	int	res;

	res = 0;
	while (n != 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		size;
	int		i;
	long	x;
	long	num;
	char	c;

	if (n == 0)
		ft_putchar_fd('0', fd);
	size = isize(n);
	num = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -(long)n;
	}
	while (size-- > 0)
	{
		x = num;
		i = 0;
		while (i++ < size)
			x = x / 10;
		c = '0' + (x % 10);
		ft_putchar_fd(c, fd);
	}
}
