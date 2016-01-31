/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:40:12 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 01:55:10 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	ft_free_menu(t_menu *menu)
{
	int	i;

	i = -1;
	while (++i < menu->nb_choices)
		free(menu->choices[i]);
	free(menu->choices);
	free(menu->title_color);
	free(menu->choice_color);
	free(menu->other_color);
	free(menu->title);
	free(menu);
}
