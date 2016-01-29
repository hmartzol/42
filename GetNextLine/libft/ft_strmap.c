/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2015/12/07 19:45:29 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;

	if (s == NULL || f == NULL)
		return (NULL);
	SMALLOC(out, char, ft_strlen(s) + 1, NULL);
	INIT(int, i, -1);
	while (s[++i])
		out[i] = (*f)(s[i]);
	out[i] = 0;
	return (out);
}
