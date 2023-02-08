/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:04:25 by llombard          #+#    #+#             */
/*   Updated: 2022/10/31 15:05:59 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	nbrs(unsigned int k, char format)
{
	if (k >= 16)
	{
		nbrs(k / 16, format);
		nbrs(k % 16, format);
	}
	else if (k > 9)
	{
		if (format == 'x')
			k = k + 87;
		else
			k = k + 55;
		write(1, &k, 1);
	}
	else
	{
		k = k + 48;
		write(1, &k, 1);
	}
}

int	ft_printfnbrexa(unsigned int nu, char format)
{
	unsigned int	k;
	unsigned int	count;

	k = 1;
	count = nu;
	nbrs(nu, format);
	while (count >= 16)
	{
		count = count / 16;
		k++;
	}
	return (k);
}
