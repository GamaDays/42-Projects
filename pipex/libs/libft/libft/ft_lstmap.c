/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaukat <tlaukat@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:21:28 by tlaukat           #+#    #+#             */
/*   Updated: 2023/11/19 16:52:32 by tlaukat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*f_ptr;

	if (!lst || !f || !del)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	f_ptr = newlst;
	if (!newlst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		newlst->next = ft_lstnew(f(lst->content));
		if (!newlst->next)
		{
			ft_lstclear(&f_ptr, del);
			return (NULL);
		}
		lst = lst->next;
		newlst = newlst->next;
	}
	return (f_ptr);
}
