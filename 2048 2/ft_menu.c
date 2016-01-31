/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:40:12 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 03:06:45 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		sf_init_menu(t_menu *m)
{
	ft_init_term(2, 0, TRUE, 0);
	nodelay(stdscr, TRUE);
	init_pair(1, m->other_color->x, m->other_color->y);
	init_pair(2, m->title_color->x, m->title_color->y);
	init_pair(3, m->choice_color->x, m->choice_color->y);
}

static void		sf_print_menu(t_menu *m, int selected)
{
	t_point			win;
	int				i;

	win = ft_size_window(stdscr);
	if (win.y > m->nb_choices + 1)
	{
		win.y = win.y / 2 - m->nb_choices / 2;
		win.x /= 2;
		i = -1;
		while (++i < m->nb_choices)
			mvprintw(win.y + i, win.x - ft_strlen(m->choices[i]) / 2,
					m->choices[i]);
		mvprintw(win.y - 2, win.x - ft_strlen(m->title) / 2, m->title);
		mvchgat(0, 0, -1, A_NORMAL, 1, NULL);
		mvchgat(win.y - 2, win.x - ft_strlen(m->title) / 2,
				ft_strlen(m->title), A_NORMAL, 2, NULL);
		mvchgat(win.y + selected, win.x - ft_strlen(m->choices[selected]) / 2,
				ft_strlen(m->choices[selected]), A_NORMAL, 3, NULL);
	}
	else
		mvprintw(0, 0, "Window too small");
	refresh();
}

int				ft_menu(t_menu *m)
{
	int		key;
	t_point	win;
	int		i;

	sf_init_menu(m);
	i = 0;
	key = 0;
	while (key != 10 && key != 27)
	{
		sf_print_menu(m, i);
		getmaxyx(stdscr, win.y, win.x);
		if (win.y > m->nb_choices + 1)
		{
			key = getch();
			if (key == 258 || key == 259)
			{
				if (key == 258)
					i = i == 4 ? 0 : i + 1;
				else
					i = i == 0 ? 4 : i - 1;
			}
		}
	}
	endwin();
	return (key == 10 ? i : -1);
}
