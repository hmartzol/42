/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 21:40:02 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 22:01:18 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	sf_check_case(int **grid, t_point p, int size)
{
	int	out;

	if (grid[p.y][p.x] == WIN_VALUE)
		return (2);
	out = !grid[p.y][p.x];
	if (p.x > 0)
		out |= (!grid[p.y][p.x - 1] || grid[p.y][p.x - 1] == grid[p.y][p.x]);
	if (p.x < size - 1)
		out |= (!grid[p.y][p.x + 1] || grid[p.y][p.x + 1] == grid[p.y][p.x]);
	if (p.y > 0)
		out |= (!grid[p.y - 1][p.x] || grid[p.y - 1][p.x] == grid[p.y][p.x]);
	if (p.y < size - 1)
		out |= (!grid[p.y + 1][p.x] || grid[p.y + 1][p.x] == grid[p.y][p.x]);
	return (out);
}

int			check_grid(int **grid, int size)
{
	t_point	pos;
	int		t;

	pos.y = -1;
	t = 0;
	while (++pos.y < size && (pos.x = -1))
		while (++pos.x < size)
			if ((t = sf_check_case(grid, pos, size)))
				return (t);
	return (0);
}
