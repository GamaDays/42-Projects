/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:03:19 by tlaukat           #+#    #+#             */
/*   Updated: 2024/02/14 18:44:28 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #Watch_DOGS

char	*ctos(int n, int *r)
{
	char	*res;
	char	c;

	c = '\0' + n;
	res = (char *)malloc(2);
	if (!res)
		return (NULL);
	if (c == 0)
	{
		*r = *r + 1;
		if (write(1, "\0", 1) == -1)
			return (NULL);
	}
	res[0] = c;
	res[1] = '\0';
	return (res);
}
