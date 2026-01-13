/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:51:31 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/20 13:50:10 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (ft_strchr(set, s1[i]) && i <= (int)ft_strlen(s1) - 1)
	{
		i++;
	}
	return (i);
}

static int	set_end(const char *s1, const char *set)
{
	int	i;

	i = ((int)ft_strlen(s1) - 1);
	while (ft_strchr(set, s1[i]) && i >= 0)
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = set_start(s1, set);
	if (start > (int)ft_strlen(s1) - 1)
		return (ft_strdup(s1 + ft_strlen(s1)));
	end = set_end(s1, set);
	ptr = malloc((end - start) + 2);
	i = 0;
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], end - start + 2);
	return (ptr);
}
