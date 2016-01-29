/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/12/07 21:15:57 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	char	*out;
	int		i;
	int		j;
	int		k;
	int		size;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	while (j > 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		--j;
	size = j - i + 1;
	if (size < 0)
		size = 0;
	if ((out = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	k = -1;
	while (++k < size)
		out[k] = s[i++];
	out[k] = 0;
	return (out);
}
