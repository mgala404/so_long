/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:55:18 by llombard          #+#    #+#             */
/*   Updated: 2022/11/02 09:58:08 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	punto(unsigned long l)
{
	if (l >= 16)
	{
		punto(l / 16);
		punto(l % 16);
	}
	else if (l > 9)
	{
		l = l + 87;
		write(1, &l, 1);
	}
	else
	{
		l = l + 48;
		write(1, &l, 1);
	}
}

int	ft_printfpointer(unsigned long k)
{
	unsigned long	j;
	unsigned long	x;

	j = 0;
	x = k;
	if (x == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	punto(k);
	while (x > 0)
	{
		x = x / 16;
		j++;
	}
	return (j + 2);
}
