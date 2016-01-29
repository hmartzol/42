/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/11/30 19:56:42 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	if (lst == NULL)
		return (NULL);
	INIT(t_list, *tmp, (*f)(lst));
	INIT(t_list, *current, ft_lstnew(tmp->content, tmp->content_size));
	if (current == NULL)
		return (NULL);
	INIT(t_list, *out, current);
	INIT(t_list, *next, NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = (*f)(lst);
		next = ft_lstnew(tmp->content, tmp->content_size);
		if (next == NULL)
			return (NULL);
		current->next = next;
		current = next;
		lst = lst->next;
	}
	return (out);
}
