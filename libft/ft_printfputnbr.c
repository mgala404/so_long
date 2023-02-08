/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:05:51 by llombard          #+#    #+#             */
/*   Updated: 2022/11/02 10:54:42 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbrwrt(int d)
{
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (d < 0)
	{
		write(1, "-", 1);
		d = -d;
	}
	if (d >= 10)
	{
		nbrwrt(d / 10);
		nbrwrt(d % 10);
	}
	else
	{
		d = d + 48;
		write(1, &d, 1);
	}
}

int	ft_printfputnbr(int d)
{
	int		c;
	long	num;

	c = 1;
	num = d;
	nbrwrt(d);
	if (num < 0)
	{
		c++;
		num = -num;
	}
	while (num >= 10)
	{
		num = num / 10;
		c++;
	}
	return (c);
}
