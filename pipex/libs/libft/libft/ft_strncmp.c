/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:56:02 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/15 16:51:42 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == (size_t)0)
		return (0);
	while (i < (n - 1) && s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
