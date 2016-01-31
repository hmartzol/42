/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:40:12 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/30 21:45:16 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

typedef struct	s_menu
{
	char		*title;
	int			nb_choices;
	char		*choices[];
}				t_menu;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

WINDOW	*ft_initterm(int mbuff, int mecho, int mkey, int mcurs)
{
	WINDOW	*out;

	out = initscr();
	start_color();
	if (mbuff == 1)
		cbreak();
	if (mbuff == 2)
		raw();
	if (mecho)
		echo();
	else
		noecho();
	keypad(out, mkey);
	curs_set(mcurs);
	return (out);
}

int		ft_menu_main(void)
{
	int				key;
	t_point			win;
	t_point			last_win;
	t_point			i;
	static const	t_menu m =
		{"2048", 5, {"Play", "Highscores", "Options", "Credits", "QUIT"}};

	ft_initterm(2, 0, TRUE, 0);
	nodelay(stdscr, TRUE);
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_RED, COLOR_YELLOW);
	i.x = 0;
	key = 0;
	while (key != 10 && key != 27)
	{
		last_win.x = win.x;
		last_win.y = win.y;
		getmaxyx(stdscr, win.y, win.x);
		if (last_win.x != win.x || last_win.y != win.y)
			erase();
		if (win.y > m.nb_choices + 1)
		{
			win.y = win.y / 2 - m.nb_choices / 2;
			win.x /= 2;
			i.y = -1;
			while (++i.y < m.nb_choices)
				mvprintw(win.y + i.y, win.x - ft_strlen(m.choices[i.y]) / 2, m.choices[i.y]);
			mvprintw(win.y - 2, win.x - ft_strlen(m.title) / 2, m.title);
			mvchgat(win.y - 2, win.x - ft_strlen(m.title) / 2, ft_strlen(m.title), A_NORMAL, 2, NULL);
			mvchgat(win.y + i.x, win.x - ft_strlen(m.choices[i.x]) / 2, ft_strlen(m.choices[i.x]), A_NORMAL, 1, NULL);
			refresh();
			key = getch();
			//mvchgat(win.y + i.x, win.x - ft_strlen(m.choices[i.x]) / 2, ft_strlen(m.choices[i.x]), A_NORMAL, 0, NULL);
			if (key == 258 || key == 259)
			{
				if (key == 258)
					i.x = i.x == 4 ? 0 : i.x + 1;
				else
					i.x = i.x == 0 ? 4 : i.x - 1;
				napms(50);
			}
		}
		else
		{
			printw("window too small");
			refresh();
		}
	}
	endwin();
	return (key == 10 ? i.x : -1);
}

int		main(void)
{
	ft_menu_main();
	return (0);
}
