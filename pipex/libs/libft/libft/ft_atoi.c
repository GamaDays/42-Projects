/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:55:32 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/15 15:26:57 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r')
		return (1);
	if (c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	ft_correction(int res, int negative)
{
	if (negative == 1)
		return (-res);
	else
		return (res);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;
	int	i;

	res = 0;
	negative = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		res *= 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (ft_correction(res, negative));
}
