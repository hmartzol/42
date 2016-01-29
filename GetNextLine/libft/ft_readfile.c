/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/06 19:18:53 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(char *path)
{
	char	buff[READBUFF];
	int		r;
	int		fd;

	INIT(int, size, 1);
	INIT(char, *t_str, NULL);
	INIT(char, *file, NULL);
	RETMSG((fd = open(path, O_RDONLY)) < 0, "Error: could not open file\n", 0);
	while ((r = read(fd, buff, READBUFF)))
	{
		SMALLOC(t_str, char, r + size, 0);
		if (file != NULL)
		{   
			ft_strcpy(t_str, file);
			free(file);
		}
		ft_memcpy(t_str + size - 1, buff, r);
		file = t_str;
		size += r;
	}
	if (file[size - 1])
		file[size - 1] = 0;
	return (file);
}
