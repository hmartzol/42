/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 03:03:26 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 18:20:16 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

t_point	ft_size_window(WINDOW *window)
{
	t_point			win;
	static t_point	last_win = {0, 0};

	getmaxyx(window, win.y, win.x);
	if (last_win.x != win.x || last_win.y != win.y)
		erase();
	last_win.x = win.x;
	last_win.y = win.y;
	return (win);
}
