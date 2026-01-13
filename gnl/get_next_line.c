/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:45:02 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/29 12:45:02 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_combine(char *s1, char *s2)
{
    char    *tmp;    
    
    tmp = ft_strjoin(s1, s2);
    free(s1);
    return (tmp);
}

char	*ft_substr(const char *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	len = ft_strlen (str);
	if (start >= len)
		return (ft_strdup(""));
	if (len - start < size)
		size = len - start;
	sub = malloc (sizeof (*sub) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = 0;
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}

char    *read_file(int fd, char *res)
{
    int     buf_res;
    char    *buffer;    

    if (!res)
        res = ft_calloc(1, 1);
    buffer = ft_calloc(BUFFER_SIZE + 1, 1);
    if (!buffer)
	{
		free (res);
		return (NULL);
	}
    buf_res = 1;
    while (buf_res > 0 && !ft_strchr(buffer, '\n'))
    {
        buf_res = read(fd, buffer, BUFFER_SIZE);
        if (buf_res == -1)
            {
                free(buffer);
                free(res);
                return (NULL);
            }
        buffer[buf_res] = '\0';
        res = ft_combine(res, buffer);
        if(!res)
            {free(buffer);
            return NULL;}
    }
    free(buffer);
    return (res);
}

/*char    *ft_get_overflow(char *res)
{
    int     i;
    int     j;
    char    *buffer;    
    
    i = 0;

    while (res[i] != '\n' && res[i] != '\0')
        i++;
    if (!res[i])
    {
        free(res);
        return (NULL);
    }
    buffer = ft_calloc(ft_strlen(res) - i + 1, 1);
    i++;
    j = 0;
    while (res[i])
    {
        buffer[j++] = res[i++];
    }
    free(res);
    return (buffer);
}*/

char    *ft_get_line(char **res)
{
    char    *line;   
    char *tmp; 
    
    tmp = *res;
    while (*tmp != '\n' && *tmp != '\0')
        tmp++;
    tmp += (*tmp == '\n');
    line = ft_substr(*res, 0, (size_t) (tmp - *res));
    if (!line)
    {
        free(*res);
        return NULL;
    }
    tmp = ft_substr (tmp, 0, ft_strlen(tmp));
    free(*res);
    *res = tmp;
    return line;
}

char    *get_next_line(int fd)
{
    static char *res;

    char        *line;    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (free(res), res = NULL, NULL);
    if(!res)
        res = ft_calloc(1,1);
    if(!res)
        return NULL;
    res = read_file(fd, res);
    if(!res)
        return NULL;
    if(!*res)
    {
        free(res);
        return NULL;
    }
    line = ft_get_line(&res);
    //res = ft_get_overflow(res);
    return (line);
}
