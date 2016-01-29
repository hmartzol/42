/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/12/07 19:27:56 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int c)
{
	char	*out;
	int		len;
	int		n;

	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 2 + (c < 0);
	n = c < 0 ? -c : c;
	while (n /= 10)
		++len;
	if ((out = (char *)malloc(len * sizeof(char))) == NULL)
		return (NULL);
	n = c < 0 ? -c : c;
	out[--len] = 0;
	if (!n)
		out[--len] = '0';
	while (n)
	{
		out[--len] = n % 10 + '0';
		n /= 10;
	}
	if (c < 0)
		out[0] = '-';
	return (out);
}
