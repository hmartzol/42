/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 21:49:44 by abrisse           #+#    #+#             */
/*   Updated: 2015/12/14 00:55:18 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n = (n / 10);
		len++;
	}
	return (len);
}

static	char	*ft_tab(int len, int n, int neg, char *str)
{
	while (len >= 0)
	{
		str[len] = (n % 10) + '0';
		n = (n / 10);
		len--;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	long long	neg;
	long long	longn;

	neg = n;
	longn = (long long)n;
	len = ft_len(longn);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (longn == -2147483648)
		return (ft_strdup("-2147483648"));
	if (longn == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (longn < 0)
		longn = -longn;
	return (ft_tab(len, longn, neg, str));
}
