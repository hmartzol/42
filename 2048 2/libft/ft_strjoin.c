/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:25:40 by abrisse           #+#    #+#             */
/*   Updated: 2015/11/30 20:51:47 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	int			a;
	int			b;

	a = 0;
	b = 0;
	while (s1[a] != '\0')
		a++;
	while (s2[b] != '\0')
		b++;
	join = (char *)malloc(a + b + 1);
	if (join == NULL)
		return (NULL);
	a = -1;
	while (s1[++a] != '\0')
		join[a] = s1[a];
	b = 0;
	while (s2[b] != '\0')
	{
		join[a] = s2[b];
		a++;
		b++;
	}
	join[a] = '\0';
	return (join);
}
