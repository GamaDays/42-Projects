/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:03:13 by tlaukat           #+#    #+#             */
/*   Updated: 2024/04/08 19:24:36 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_chr(char c, int *res)
{
	int	i;

	i = write(FT_PRINTF_FD, &c, 1);
	if (i == -1)
		return (-1);
	*res += 1;
	return (1);
}

static int	put_str(char *out, int *res)
{
	int	i;

	i = write(FT_PRINTF_FD, out, ft_strlen(out));
	if (i == -1)
	{
		free(out);
		return (-1);
	}
	*res += i;
	return (0);
}

static char	*to_string(char c, va_list *ptr, int *res)
{
	if (c == 'c')
		return (ctos(va_arg(*ptr, int), res));
	if (c == 's')
		return (stos((char *)va_arg(*ptr, const char *)));
	if (c == 'p')
		return (ptos((unsigned long long)va_arg(*ptr, unsigned long long)));
	if (c == 'i' || c == 'd')
		return (ft_itoa(va_arg(*ptr, int)));
	if (c == 'u')
		return (utos((unsigned int)va_arg(*ptr, unsigned int)));
	if (c == 'x')
		return (htos((unsigned int)va_arg(*ptr, unsigned int), 'h'));
	if (c == 'X')
		return (htos((unsigned int)va_arg(*ptr, unsigned int), 'H'));
	if (c == '%')
		return (ft_strdup("%"));
	return (NULL);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		res;
	char	*out;

	va_start(ptr, s);
	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			out = to_string(s[i], &ptr, &res);
			if (!out || put_str(out, &res) == -1)
				return (-1);
			free(out);
		}
		else if (put_chr(s[i], &res) == -1)
			return (-1);
		i++;
	}
	va_end(ptr);
	return (res);
}

/*int	main(void)
{
	int	resft;
	int	res;

	resft = ft_printf(" %c %c %c ", '0', 0, '1');
	res = printf(" %c %c %c ", '0', 0, '1');
	printf("resft: %d\nres: %d", resft, res);
}*/
