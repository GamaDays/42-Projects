/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:35:35 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/20 13:44:17 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;
	int	j;

	i = 0;
	if (haystack == NULL && n == 0)
		return (NULL);
	if (needle && (*needle == '\0' || haystack == needle))
		return ((char *)haystack);
	if (n > ft_strlen(haystack))
		n = ft_strlen(haystack);
	while (i < (int)n && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[j + i] && i + j < (int)n)
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
