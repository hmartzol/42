/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:27:17 by abrisse           #+#    #+#             */
/*   Updated: 2016/01/28 18:08:37 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(const char *s)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**tab;

	tab = (char **)malloc(sizeof(*tab) * (ft_strlen(s)));
	i = 0;
	j = 0;
	if (!tab)
		return (NULL);
	if (s[0] != '\0')
	{
		while (s[i] != '\0')
		{
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
				i++;
			start = i;
			while (s[i] != '\0' && (s[i] != ' ' && s[i] != '\t'))
				i++;
			if (i > start)
				tab[j++] = ft_strsub(s, start, (i - start));
		}
	}
	tab[j] = NULL;
	return (tab);
}
