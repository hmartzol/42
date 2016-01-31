/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:44:17 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 19:42:00 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <stdio.h> //

void	fill_case(int **grid, int side)
{
	t_point	*tmp;
	t_point	n;
	t_point	pos;

	if ((tmp = (t_point*)malloc(sizeof(t_point) * side * side)) == NULL)
		return ;
	ft_ptinit(&n, 0, side * side - 1);
	pos.x = -1;
	while (++pos.x < side && (pos.y = -1))
		while (++pos.y < side)
			if (grid[pos.y][pos.x])
				ft_ptinit(&tmp[n.y--], pos.x, pos.y);
			else
				ft_ptinit(&tmp[n.x++], pos.x, pos.y);
	pos = tmp[rand() % n.x];
	grid[pos.y][pos.x] = (rand() % 2 + 1) * 2;
	free(tmp);
}
