#include "get_next_line.h"

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
    char    *res;    res = (char *)s;
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

static int  mits(int *i, int *j, char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return (1);
    *i = 0;
    *j = 0;
    return (0);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *ptr;
    int     i;
    int     j;    if (mits(&i, &j, s1, s2) == 1)
        return (NULL);
    ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (ptr == NULL)
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
