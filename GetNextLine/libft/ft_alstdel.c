/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/11/30 19:47:32 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_alstdel(t_alist *lst, void (*del)(void *, size_t))
{
	if (lst != NULL)
		lst = ft_alsttop(lst);
	else
		return ;
	ft_alstdel(lst->next, del);
	ft_alstdelone(lst, del);
}
