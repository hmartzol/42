/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:27:44 by abrisse           #+#    #+#             */
/*   Updated: 2015/11/30 20:47:07 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*cpy;
	char		*cpycpy;
	int			i;
	int			j;
	int			k;

	i = 0;
	j = -1;
	k = ft_strlen(s) - 1;
	cpy = (char *)malloc(sizeof(*cpy) * (k + 2));
	if (cpy == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	while (i < k + 1)
	{
		cpy[++j] = s[i];
		i++;
	}
	cpy[j + 1] = '\0';
	cpycpy = (char *)malloc(sizeof(*cpycpy) * ft_strlen(cpy) + 1);
	ft_strcpy(cpycpy, cpy);
	return (cpycpy);
}
