/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 02:29:24 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 03:48:03 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

#define GS 4

void	print_grid(int	**grid)
{
	int		i;
	int		j;
	int		t;
	t_point	win;

	(void)grid;
	ft_init_term(2, 0, TRUE, 0);
	nodelay(stdscr, FALSE);
	win = ft_size_window(stdscr);
	erase();
	i = -1;
	while (++i < win.x && (j = -1))
		while (++j < win.y)
		{
			t = (!i | (i == (win.x / GS)) | (i == (win.x / GS) * 2) |
				(i == (win.x / GS) * 3) | i == win.x -1) * 2 + (!j |
				(j == (win.y / GS)) | (j == (win.y / GS) * 2) |
				(j == (win.y / GS) * 3) | j == win.y - 1);
			if (t == 1)
				mvprintw(j, i, "-");
			if (t == 2)
				mvprintw(j, i, "|");
			if (t == 3)
				mvprintw(j, i, "+");
		}
	refresh();
	getch();
	endwin();
}
