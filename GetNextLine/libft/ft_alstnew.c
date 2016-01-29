/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/06 19:18:53 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alist	*ft_alstnew(int id, void *content, size_t content_size)
{
	if (content == NULL)
		content_size = 0;
	INIT(t_alist, *out, NULL);
	SMALLOC(out, t_alist, 1, NULL);
	out->id = id;
	INIT(unsigned char, *tmp, NULL);
	if (content_size)
		SMALLOC(tmp, unsigned char, content_size, NULL);
	if (content == NULL)
		out->content = NULL;
	else
		out->content = ft_memcpy(tmp, content, content_size);
	out->content_size = content_size;
	out->last = out->next = NULL;
	return (out);
}
