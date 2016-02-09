/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:41:49 by mjuffard          #+#    #+#             */
/*   Updated: 2016/02/07 22:21:47 by mjuffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_count_diese(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '#')
			j++;
		i++;
	}
	return (j);
}

int	ft_count_point(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '.')
			j++;
		i++;
	}
	return (j);
}

int	ft_count_backslash_n(char *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '\n')
			j++;
		i++;
	}
	return (j);
}
