/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:16:53 by abrisse           #+#    #+#             */
/*   Updated: 2015/12/01 13:30:20 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int a;
	int negative;
	int nbr;

	negative = 1;
	a = 0;
	nbr = 0;
	while (str[a] == ' ' || str[a] == '\n' || str[a] \
	== '\t' || str[a] == '\r' || str[a] == '\v' || str[a] == '\f')
		a++;
	if (str[a] == '-')
		negative = -1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] != '\0' && str[a] >= '0' && str[a] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (str[a] - '0');
		a++;
	}
	return (nbr * negative);
}
