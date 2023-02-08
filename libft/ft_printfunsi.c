/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:33:23 by llombard          #+#    #+#             */
/*   Updated: 2022/11/02 09:39:04 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	scrive(unsigned int u)
{
	unsigned int	num;

	num = u;
	if (num >= 10)
	{
		scrive(num / 10);
		scrive(num % 10);
	}
	else
	{
		num = num + 48;
		write (1, &num, 1);
	}
}

int	ft_printfunsi(unsigned int u)
{
	unsigned int	k;
	unsigned int	num;

	num = u;
	scrive(u);
	if (num == 0)
		return (1);
	k = 0;
	while (num > 0)
	{
		num = num / 10;
		k++;
	}
	return (k);
}
