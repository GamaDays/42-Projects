#include "get_next_line.h"

char    *ft_combine(char *s1, char *s2)
{
    char    *tmp;    
    tmp = ft_strjoin(s1, s2);
    free(s1);
    return (tmp);
}

char    *read_file(int fd, char *res)
{
    int     buf_res;
    char    *buffer;    if (!res)
        res = ft_calloc(1, 1);
    buffer = ft_calloc(BUFFER_SIZE + 1, 1);
    buf_res = 1;
    while (buf_res > 0)
    {
        buf_res = read(fd, buffer, BUFFER_SIZE);
        if (buf_res == -1)
            {
                free(buffer);
                return (NULL);
            }
        buffer[buf_res] = '\0';
        res = ft_combine(res, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    return (res);
}

char    *ft_get_overflow(char *res)
{
    int     i;
    int     j;
    char    *buffer;    i = 0;    while (res[i] != '\n' && res[i] != '\0')
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
}

char    *ft_get_line(char *res)
{
    int     i;
    char    *buffer;    i = 0;
    if(!res[i])
        return NULL;
    while (res[i] != '\n' && res[i] != '\0')
        i++;
    buffer = ft_calloc(i + 2, 1);
    i=0;
    while (res[i] != '\n' && res[i] != '\0')
    {
        buffer[i] = res[i];
        i++;
    }
    if (res[i] && res[i] == '\n')
        buffer[i++] = '\n';
    return (buffer);
}

char    *get_next_line(int fd)
{
    static char *res;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) <0)
        {
        if(res)
            free(res); 
        res = NULL;
        return (NULL);
        }
    res = read_file(fd, res);
    if(!res)
        return NULL;
    line = ft_get_line(res);
    res = ft_get_overflow(res);
    return (line);
}
