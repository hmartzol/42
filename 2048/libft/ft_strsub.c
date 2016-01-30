/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:27:33 by abrisse           #+#    #+#             */
/*   Updated: 2015/11/30 15:50:58 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;
	unsigned int	n;

	i = start;
	n = (unsigned int)len;
	cpy = (char *)malloc(sizeof(*cpy) * (len + 1));
	if (!cpy)
		return (NULL);
	while (i < (start + n))
	{
		cpy[i - start] = s[i];
		i++;
	}
	cpy[i - start] = '\0';
	return (cpy);
}
