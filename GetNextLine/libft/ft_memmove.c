/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/12/18 18:17:53 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	INIT(size_t, i, -1);
	if ((long)dst > (long)src)
		while (1 + --len)
			*((unsigned char*)dst + len) = *((unsigned char*)src + len);
	else
		while (++i < len)
			*((unsigned char*)dst + i) = *((unsigned char*)src + i);
	return (dst);
}
