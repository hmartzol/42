/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:52:52 by hmartzol          #+#    #+#             */
/*   Updated: 2015/11/30 19:05:54 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	return (c == 32 || (c > 8 && c < 14));
}

int				ft_atoi(const char *str)
{
	int		out;
	int		sign;
	char	*p_tmp;

	p_tmp = (char*)str;
	sign = 1;
	out = 0;
	while (ft_isspace(*p_tmp))
		++p_tmp;
	if (*p_tmp == '+' || *p_tmp == '-')
		if (*p_tmp++ == '-')
			sign = -1;
	while (ft_isdigit(*p_tmp))
		out = 10 * out + *p_tmp++ - '0';
	return (sign * out);
}
