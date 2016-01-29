/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:39:36 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/06 19:18:53 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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
	INIT(int, i, -1)
	INIT(int, pcount, -1)
	while (file[++i] && file[i - (i > 0)])
	{
		INIT(int, j, -1)
		piece[++pcount].i = 0;
		while (++j < 20 && file[i + j])
			if (j % 5 == 4)
			{
				RETMSG(file[i + j] != '\n', "Missing back1\n", -1)
			}
			else
			{
				RETMSG(file[i + j] != '.' && file[i + j] != '#', "!=.#\n", -1)
				piece[pcount].c[j / 5] |=
					(file[i + j] == '#') << (7 - (j % 5));
			}
		i += j;
		RETMSG(file[i] != '\n' && file[i], "Missing back2\n", -1)
	}
	return (pcount + 1);
}

int prepare_piece(t_piece piece[26], int pcount)
{
	INIT(int, i, -1)
	while (++i < pcount)
	{
		RETMSG(!piece[i].i, "Blanck piece\n", 0)
		while (!piece[i].c[0])
			piece[i].i >>= 8;
		while (!((piece[i].c[0] & 128) | (piece[i].c[1] & 128) |
				(piece[i].c[2] & 128)))
			piece[i].i <<= 1;
		INIT(int, j, -1)
		INIT(int, ok, 0);
		while (++j < 19 && !ok)
			ok |= (g_ref[j] == piece[i].i);
		RETMSG(!ok, "Incorect piece\n", 0)
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_piece piece[26];

	RETMSG(argc != 2, "Usage: ./fillit <filename>\n", 0)
	INIT(char, *file, ft_readfile(argv[1]))
	INIT(int, pcount, 0)
	RETMSG(!(pcount = load_pieces(file, piece)), "No pieces\n", 0)
	prepare_piece(piece, pcount);
	return (0);
}
