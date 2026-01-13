/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:25 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/17 13:04:50 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	arg1;
	char			arg2;
	char			*res;
	int				i;

	i = 0;
	res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < (int)ft_strlen(s))
	{
		arg1 = i;
		arg2 = s[i];
		res[i] = f(arg1, arg2);
		i++;
	}
	res[i] = '\0';
	return (res);
}
