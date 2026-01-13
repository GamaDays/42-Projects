/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:04:33 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/20 11:56:33 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	if (c < 0)
		return (NULL);
	while (c >= 256)
		c = c - 256;
	while (*res != '\0' && *res != c)
	{
		res++;
	}
	if (*res == c)
	{
		return (res);
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strchr("tripouille", ('t' + 256)));
	printf("%s\n", strchr("tripouille", 't' + 256));
}*/