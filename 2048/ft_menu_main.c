/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:40:12 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 02:58:10 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		sf_auteur(WINDOW *window)
{
	int		i;
	t_point	winsize;
	char	buff[80];
	char	*tmp;

	getmaxyx(window, winsize.y, winsize.x);
	read(i = open("./auteur", O_RDONLY), buff, 80);
	close(i);
	mvwprintw(window, winsize.y / 2, winsize.x / 2 - 15, "Made by:");
	i = (int)(ft_strchr(buff, '\n') - buff);
	tmp = ft_strsub(buff, 0, (size_t)i);
	mvwprintw(window, winsize.y / 2, winsize.x / 2 - 6, tmp);
	free(tmp);
	mvwprintw(window, winsize.y / 2, winsize.x / 2 - 5 + i, "and:");
	tmp = ft_strsub(buff, i + 1, (size_t)(ft_strrchr(buff, '\n') - buff - i));
	mvwprintw(window, winsize.y / 2, winsize.x / 2 + i, tmp);
	free(tmp);
}

static t_menu	*sf_init_main_menu(void)
{
	t_menu				*out;
	static const char	*options[] = {"Play", "Highscores", "Options",
										"Credits", "QUIT"};

	out = (t_menu*)malloc(sizeof(t_menu));
	out->title = ft_strdup("2048");
	out->title_color = ft_ptnew(1, 3);
	out->choice_color = ft_ptnew(0, 2);
	out->other_color = ft_ptnew(7, 0);
	out->nb_choices = -1;
	out->choices = (char **)malloc(5 * sizeof(char *));
	while (++out->nb_choices < 5)
		out->choices[out->nb_choices] = ft_strdup(options[out->nb_choices]);
	return (out);
}

int				ft_menu_main(void)
{
	int		choice;
	t_point	winsize;
	t_menu	*main_menu;

	main_menu = sf_init_main_menu();
	choice = 0;
	while (choice != -1 && choice != 4)
	{
		choice = ft_menu(main_menu);
		ft_init_term(2, 0, TRUE, 0);
		nodelay(stdscr, FALSE);
		getmaxyx(stdscr, winsize.y, winsize.x);
		erase();
		if (choice == -1 || choice == 4)
			mvprintw(winsize.y / 2, winsize.x / 2 - 30,
			"You're SURE you're leaving us already? :'(   (PRESS ANY KEY)");
		if (choice == 3)
			sf_auteur(stdscr);
		getch();
		erase();
		refresh();
		endwin();
	}
	ft_free_menu(main_menu);
	return (0);
}
