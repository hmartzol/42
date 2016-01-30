/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:25:51 by abrisse           #+#    #+#             */
/*   Updated: 2015/11/30 20:51:05 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	x;
	size_t	a;
	size_t	b;

	x = 0;
	a = 0;
	b = 0;
	while (src[a] != '\0')
		a++;
	while (dst[x] != '\0')
		x++;
	ret = (x + a);
	while (src[b] != '\0' && x < size - 1)
	{
		dst[x] = src[b];
		x++;
		b++;
	}
	dst[x] = '\0';
	if (size > x)
		return (ret);
	else
		return (a + size);
}
