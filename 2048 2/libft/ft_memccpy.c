/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:18:56 by abrisse           #+#    #+#             */
/*   Updated: 2015/12/11 21:49:59 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	ptr1 = (char *)dst;
	ptr2 = (char *)src;
	i = 0;
	while (i < n && ptr2[i] != (char)c)
	{
		ptr1[i] = (char)ptr2[i];
		i++;
	}
	if (ptr2[i] == (char)c && i < n)
	{
		ptr1[i] = (char)ptr2[i];
		return (&ptr1[i + 1]);
	}
	return (NULL);
}
