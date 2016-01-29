/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/12/20 17:19:39 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	INIT(size_t, srclen, ft_strlen(src));
	INIT(size_t, dstlen, ft_strlen(dst));
	INIT(int, i, -1);
	while (++i < (int)(dstsize - dstlen - 1) && src[i])
		dst[i + dstlen] = src[i];
	dst[i + dstlen - 1] = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	return (srclen + dstlen);
}
