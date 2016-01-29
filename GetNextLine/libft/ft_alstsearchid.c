/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alstsearchid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/12/20 19:21:11 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alist	*ft_alstsearchid(int id, t_alist *lst)
{
	if (lst == NULL || lst->id == id)
		return (lst);
	INIT(t_alist, *top, lst);
	INIT(t_alist, *bot, lst);
	while (top->id != id && bot->id != id && (top->last || bot->next))
	{
		top = top->last;
		bot = bot->next;
	}
	if (top && top->id == id)
		return (top);
	if (bot && bot->id == id)
		return (bot);
	return (NULL);
}
