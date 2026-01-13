/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:37:25 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/29 12:37:25 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char const *str)
{
	char	*dup;
	char	*ptr;

	dup = malloc (sizeof (*dup) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	ptr = dup;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (dup);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*res;
    size_t	i;
    size_t n = elementSize * elementCount;

	res = malloc(n);
	if (!res)
		return (NULL);
    i = 0;
	while (i < n)
	{
		res[i] = '\0';
		i++;
	}
	return (res);

}

size_t  ft_strlen(const char *str)
{
    size_t  i;    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    char    *res;    
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

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *ptr;
    int     i;
    int     j;    
    
    i=0;
    j=0;
    ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!ptr || !s1 || !s2)
        return (NULL);
    while (s1[j] != '\0')
    {
        ptr[i] = s1[j];
        i++;
        j++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        ptr[i] = s2[j];
        i++;
        j++;
    }
    ptr[i] = '\0';
    return (ptr);
}
