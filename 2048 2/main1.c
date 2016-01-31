/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:40:12 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/30 20:51:40 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

typedef struct	s_menu
{
	char		*title;
	int			nb_choices;
	char		*choices[];
}				t_menu;

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
	int				i;
	int				w_lines;
	int				w_columns;
	static const	t_menu m =
		{"2048", 5, {"Play", "Highscores", "Options", "Credits", "QUIT"}};

	ft_initterm(2, 0, TRUE, 0);
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_RED, COLOR_YELLOW);
	getmaxyx(stdscr, w_lines, w_columns);
	if (w_lines > m.nb_choices + 1)
	{
		w_lines = w_lines / 2 - m.nb_choices / 2;
		w_columns /= 2;
		i = -1;
		while (++i < m.nb_choices)
			mvprintw(w_lines + i, w_columns - ft_strlen(m.choices[i]) / 2, m.choices[i]);
		mvprintw(w_lines - 2, w_columns - ft_strlen(m.title) / 2, m.title);
		mvchgat(w_lines - 2, w_columns - ft_strlen(m.title) / 2, ft_strlen(m.title), A_NORMAL, 2, NULL);
		i = 0;
		key = 0;
		while (key != 10 && key != 27)
		{
			mvchgat(w_lines + i, w_columns - ft_strlen(m.choices[i]) / 2, ft_strlen(m.choices[i]), A_NORMAL, 1, NULL);
			refresh();
			key = getch();
			mvchgat(w_lines + i, w_columns - ft_strlen(m.choices[i]) / 2, ft_strlen(m.choices[i]), A_NORMAL, 0, NULL);
			i += (key == 258 && i < 4) - (key == 259 && i > 0);
		}
		endwin();
		return (key == 10 ? i : -1);
	}
	printw("window too small");
	refresh();
	endwin();
	return (-1);
}

int		main(void)
{
	ft_menu_main();
	return (0);
}
