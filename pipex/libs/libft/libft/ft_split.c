/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:27:35 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/20 13:34:27 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			res++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	size_t	len;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (s && *s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			if (ft_strchr(s, c) != NULL)
				len = (size_t)(ft_strchr(s, c) - s);
			else
				len = (size_t)ft_strlen(s);
			res[i] = ft_substr(s, 0, len);
			i++;
			s = s + len;
		}
	}
	res[i] = NULL;
	return (res);
}
