/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:19:04 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/19 17:20:14 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	t;
	int		i;
	int		j;

	i = ft_strlen(d);
	j = 0;
	if (n > (size_t)ft_strlen(d))
		t = (size_t)ft_strlen(d) + (size_t)ft_strlen(s);
	else
		t = n + (size_t)ft_strlen(s);
	while (i < (int)n - 1 && s[j])
	{
		d[i] = s[j];
		i++;
		j++;
	}
	d[i] = '\0';
	return (t);
}
