/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:43:13 by mgala             #+#    #+#             */
/*   Updated: 2022/11/03 16:56:09 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long	numerolungolungo(int n)
{
	long	x;
	long	y;

	x = n;
	y = 0;
	if (x > 0)
	{
		while (x >= 1)
		{
			x /= 10;
			y++;
		}
	}
	else
	{
		y = 1;
		while (x < 0)
		{
			x /= 10;
			y++;
		}
	}
	return (y);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	y;
	long	z;

	if (n < 0)
	{
		y = n;
		y = -y;
	}
	else
		y = n;
	z = numerolungolungo(n);
	str = malloc(sizeof(char) * (z + 1));
	str[z--] = '\0';
	while (z >= 0)
	{
		str[z] = (y % 10) + 48;
		y /= 10;
		z--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
