/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 20:54:27 by abrisse           #+#    #+#             */
/*   Updated: 2016/01/31 03:20:26 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft/libft.h"
# include <stdlib.h>
# include <time.h>
# include <signal.h>
# include <curses.h>
# include <fcntl.h>

enum	e_conts
{
	WIN_VALUE = 2048
};

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_menu
{
	char		*title;
	int			nb_choices;
	t_point		*title_color;
	t_point		*choice_color;
	t_point		*other_color;
	char		**choices;
}				t_menu;

WINDOW	*ft_init_term(int mbuff, int mecho, int mkey, int mcurs);
int		ft_menu(t_menu *m);
int		ft_menu_main(void);
t_point	*ft_ptnew(int x, int y);
void	ft_free_menu(t_menu *menu);
t_point	ft_size_window(WINDOW *window);
void	print_grid(int **grid);

#endif
