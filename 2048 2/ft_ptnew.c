/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 01:29:49 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 01:52:10 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

t_point	*ft_ptnew(int x, int y)
{
	t_point	*out;

	if ((out = (t_point*)malloc(sizeof(t_point))) == NULL)
		return (NULL);
	out->x = x;
	out->y = y;
	return (out);
}
