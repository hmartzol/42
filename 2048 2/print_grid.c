/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 02:29:24 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 23:28:59 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	sf_print_case(WINDOW *window, t_point pos, int n, int side)
{
	t_point	win;
	char	*tmp;

	(void)side;
	win = ft_size_window(window);
	tmp = ft_itoa(n);
	mvwprintw(window, pos.y + 1, pos.x + 1, tmp);
	free(tmp);
}

void		print_grid(WINDOW *w, int **grid, int s)
{
	t_point	p;
	int		k;
	int		t;
	t_point	win;
	t_point	c;

	win = ft_size_window(w);
	ft_ptinit(&win, win.x - 1, win.y - 1);
	ft_ptinit(&c, 0, 0);
	erase();
	p.x = -1;
	while (++p.x <= win.x && (p.y = -1))
		while (++p.y <= win.y && (k = -1))
		{
			t = 0;
			while (++k <= s)
				t |= (p.x == (win.x * k) / s) * 2 | (p.y == (win.y * k) / s);
			if (t == 1)
				mvwprintw(w, p.y, p.x, "-");
			if (t == 2)
				mvwprintw(w, p.y, p.x, "|");
			if (t == 3)
			{
				mvwprintw(w, p.y, p.x, "+");
				if (p.x != win.x && p.y != win.y)
				{
					sf_print_case(w, p, grid[c.x++][c.y], s);
					c.x = c.x == s ? 0 * (++c.y) : c.x;
				}
			}
		}
	refresh();
}
