/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 21:31:34 by hmartzol          #+#    #+#             */
/*   Updated: 2016/01/31 21:37:25 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	power_check(int	n)
{
	while (!(n & 1))
		n >>= 1;
	return (!(n & 0xFFFFFFFE));
}
