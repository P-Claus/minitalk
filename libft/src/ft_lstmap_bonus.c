/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:23:26 by pclaus            #+#    #+#             */
/*   Updated: 2023/11/07 18:24:38 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*elem;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	if (!new_list)
		return (NULL);
	elem = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew((*f)(lst->content));
		if (!new_list->next)
		{
			ft_lstclear(&elem, del);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (elem);
}
