/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:40:12 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/30 21:55:48 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

WINDOW	*ft_init_term(int mbuff, int mecho, int mkey, int mcurs)
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
