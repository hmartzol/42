/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/02/08 21:18:44 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

typedef union
{
	unsigned char c[4];
	unsigned long int i;
} t_piece;

unsigned long int g_ref[19] = {49344, 240, 2155905152, 49248, 4243584, 24768,
8437824, 16608, 8437888, 57408, 4243520, 32992, 4210880, 57376, 12615808, 8416,
8421568, 57472, 12599360};

int load_pieces(char *file, t_piece piece[26])
{
	int	i;
	int	pcount;
	int j;

	i = -1;
	pcount = -1;
	while (file[++i] && file[i - (i > 0)])
	{
		j = -1;
		piece[++pcount].i = 0;
		while (++j < 20 && file[i + j])
			if (j % 5 == 4)
			{
				if (file[i + j] != '\n')
				{
					ft_putendl("Missing back 1");
					return (-1);
				}
			}
			else
			{
				if (file[i + j] != '.' && file[i + j] != '#')
				{
					ft_putendl("Unknown/bad number of character");
					return (-1);
				}
				piece[pcount].c[j / 5] |=
					(file[i + j] == '#') << (7 - (j % 5));
			}
		i += j;
		if (file[i] != '\n' && file[i])
		{
			ft_putendl("Missing back 2");
			return (-1);
		}
	}
	return (pcount + 1);
}

int prepare_piece(t_piece piece[26], int pcount)
{
	int	i;
	int	j;
	int	ok;

	i = -1;
	while (++i < pcount)
	{
		if (!piece[i].i)
		{
			ft_putendl("Blanck piece");
			return (0);
		}
		while (!piece[i].c[0])
			piece[i].i >>= 8;
		while (!((piece[i].c[0] & 128) | (piece[i].c[1] & 128) |
				(piece[i].c[2] & 128)))
			piece[i].i <<= 1;
		j = -1;
		ok = 0;
		while (++j < 19 && !ok)
			ok |= (g_ref[j] == piece[i].i);
		if (!ok)
		{
			ft_putendl("Incorrect piece");
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_piece piece[26];
	char	*file;
	int		pcount;
	int		fd;

	if (argc != 2)
	{
	   ft_putendl("Usage: ./fillit <filename>");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	file = ft_readfile(fd);
	close(fd);
	if (!(pcount = load_pieces(file, piece)))
	{
		ft_putendl("No pieces");
		return (0);
	}
	if (pcount > 26)
	{
		ft_putendl("Too much pieces");
		return (0);
	}
	prepare_piece(piece, pcount);
	return (0);
}
