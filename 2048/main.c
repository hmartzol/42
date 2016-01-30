/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 21:01:47 by abrisse           #+#    #+#             */
/*   Updated: 2016/01/30 11:03:02 by malaine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	ft_win(void)
{
	int i;
	int l;
	int c;
	int s;
	int cols;
	int lines;

	i = 0;
	initscr();
	napms(200);
	getmaxyx(stdscr, lines, cols);
	l = 1;
	while (l <= lines)
	{
		c = 1;
		while (c <= cols)
		{
			if (cols < 29 || lines < 17)
			{
				s = 0;
				while (s++ < LINES)
					ft_putchar('\n');
				s = 0;
				while (s++ < (COLS / 2) - 4)
					ft_putchar(' ');
				ft_putstr("TOO SMALL");
				s = 0;
				while (s++ < LINES / 2)
					ft_putchar('\n');
				endwin();
				break ;
			}
			else
			{
				if ((l == 1 || l == 1 + (lines / 4) ||\
	l == 1 + (lines / 4) * 2) || l == 1 + ((lines / 4) * 3) || l == lines)
					ft_putchar('o');
				else if (c == 1 || c == 1 + (cols / 4) ||\
	c == 1 + ((cols / 4) * 2) || c == 1 + ((cols / 4) * 3) || c == cols)
					ft_putchar('o');
				else
					ft_putchar(' ');
				c++;
			}
		}
		l++;
	}
	refresh();
	endwin();
}

int		main(void)
{
	int copycols;
	int copylines;

	copycols = 0;
	copylines = 0;
	ft_win();
	while (42)
	{
		initscr();
		napms(200);
		if (copylines != LINES || copycols != COLS)
		{
			endwin();
			ft_win();
		}
		else
		{
			copylines = LINES;
			copycols = COLS;
			refresh();
			endwin();
		}
	}
	return (0);
}
