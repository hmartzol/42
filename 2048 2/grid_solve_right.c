/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_solve_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:07:19 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 23:38:57 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	sf_wrap(int	**grid, int size, int p)
{
	int	out;
	int	i;
	int	t;

	out = 0;
	t = 0;
	i = -1;
	while (++i < size)
		if (grid[p][size - 1 - i])
		{
			grid[p][size - 1 - t] = grid[p][size - 1 - i];
			if (t++ != i)
			{
				grid[p][size - 1 - i] = 0;
				out = 1;
			}
		}
	return (out);
}

int	grid_solve_right(int **grid, int size)
{
	int		out;
	t_point	pos;

	pos.y = -1;
	out = 0;
	while (++pos.y < size)
	{
		out |= sf_wrap(grid, size, pos.y);
		pos.x = -2;
		while ((pos.x += 2) < size - (size % 2))
			if (grid[pos.y][size - 1 - pos.x] == grid[pos.y][size - pos.x])
			{
				out += (grid[pos.y][size - pos.x] *= 2);
				out |= !(grid[pos.y][size - 1 - pos.x] = 0);
			}
		out |= sf_wrap(grid, size, pos.y);
	}
	return ((out & 1) ? (out - 1) : -1);
}
