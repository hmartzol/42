/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/06 19:18:53 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
static s_list	*lsearch(s_list **alst, int const fd)
{
	s_list	out;

	if (*alst = NULL)
		return (NULL);
	out = *alst;
	while (out != NULL && out->content-size != fd)
		out = out->next;
	return (out);
}
*/

static int		ft_readc(int const fd, char **out, const int c)
{
	int		t;
	char	buff[BUFF_SIZE];
	char	*tmp;
	int		size;

	size = 1;
	while ((t = read(fd, buff, BUFF_SIZE)) > 0 && ((*out != NULL
			&& ft_memchr(*out, c, t) == NULL) || *out == NULL))
	{
		if ((tmp = (char *)malloc(sizeof(char) * (t + size))) == NULL)
			return (-1);
		if (*out != NULL)
		{
			ft_strcpy(tmp, *out);
			free(*out);
		}
		ft_memcpy(tmp + size - 1, buff, t);
		*out = tmp;
		size += t;
	}
	if (*out != NULL && *out[size - 1])
		(*out)[size - 1] = 0;
	return (SIGN(t));
}

/*
int				get_next_line(int const fd, char **line)
{
	static s_list	*st_list[1] = {NULL};
	s_list			node;
	char			buff[BUFF_SIZE];
	int				i;

	node = lsearch(st_list, fd);
	if (node == NULL || ft_strchr(node->content, '\n') == NULL)
	{
		if ((i = read(fd, buff, BUFF_SIZE)) != BUFF_SIZE)
		{
			if (i > 0)
			{
				if ((*line = (char*)malloc((i + 1) * sizeof(char))) == NULL)
					return (-1);
				ft_memmove(*line, buff, i);
				(*line)[i] = 0;
				return (1);
			}
			else
				return (-(i < 0));
		}
	}
	else
		
}
*/

int				main()
{
	int		fd = open("get_next_line.c", O_RDONLY);
	char	*str[1] = {NULL};
	printf("%d\n%s\n", ft_readc(fd, str, '\n'), *str);
	return (0);
}
