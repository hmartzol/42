/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/12/20 17:38:59 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str1, char *str2, size_t n)
{
	size_t	j;

	if (!*str2)
		return (str1);
	INIT(size_t, i, -1);
	while (++i < n && str1[i] && !(j = 0))
		while (str2[j] == str1[j + i])
			if (i + j++ < n && !str2[j])
				return (str1 + i);
	return (0);
}
