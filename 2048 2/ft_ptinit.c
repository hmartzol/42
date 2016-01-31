/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:59:29 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 19:21:06 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

t_point	ft_ptinit(t_point *p, int x, int y)
{
	t_point tmp;

	tmp.x = x;
	tmp.y = y;
	if (p)
		*p = tmp;
	return (tmp);
}
