/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/12/18 18:16:14 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	unsigned char	*tmp;
	t_list			*out;

	if (content == NULL)
		content_size = 0;
	SMALLOC(out, t_list, 1, NULL);
	if (content_size)
		SMALLOC(tmp, unsigned char, content_size, NULL);
	if (content == NULL)
		out->content = NULL;
	else
		out->content = ft_memcpy(tmp, content, content_size);
	out->content_size = content_size;
	out->next = NULL;
	return (out);
}
