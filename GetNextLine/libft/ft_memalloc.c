/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:49:14 by hmartzol          #+#    #+#             */
/*   Updated: 2015/11/30 19:57:57 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *out;

	out = (unsigned char*)malloc(size * sizeof(unsigned char));
	if (out == NULL)
		return (NULL);
	while (size--)
		out[size] = 0;
	return ((void *)out);
}
