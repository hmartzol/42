/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_highscores.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:26:18 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 18:26:37 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"
#include <stdio.h> //

void	print_highscores(void)
{
	char	str[BUFFSIZE];
	char	**tab;
	char	**scores;
	int		i;
	t_point	t;

	ft_init_term(2, 0, TRUE, 0);
	t = ft_size_window(stdscr);
	read(i = open(HIGHPATH, O_RDONLY), str, BUFFSIZE);
	if (i < 0)
		mvprintw(t.y / 2, t.x / 2 - 15, "You don't have any scores yet.\n");
	scores = ft_strcsplit(str, '\n');
	close(i);
	i = -1;
	while (scores[++i])
	{
		tab = ft_strcsplit(scores[i], ' ');
		mvprintw(t.y / 2 + i, t.x / 2 - ft_strlen(tab[1]) - 2, tab[1]);
		mvprintw(t.y / 2 + i, t.x / 2 - 1, "by");
		mvprintw(t.y / 2 + i, t.x / 2 + 2, tab[0]);
		ft_tabfree(tab);
	}
	getch();
	ft_tabfree(scores);
	endwin();
}
