/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:35:52 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/19 15:41:39 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*l;

	if (!del || !lst)
		return ;
	while (*lst != NULL)
	{
		l = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = l;
	}
}
