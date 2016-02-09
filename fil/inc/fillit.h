/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 21:13:47 by mjuffard          #+#    #+#             */
/*   Updated: 2016/02/07 21:23:30 by mjuffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include<stdio.h>

int		ft_count_diese(char *tab);
int		ft_count_point(char *tab);
int		ft_count_backslash_n(char *tab);

#endif
