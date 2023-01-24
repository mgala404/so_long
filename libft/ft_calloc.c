/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:25:11 by mgala             #+#    #+#             */
/*   Updated: 2022/10/27 15:40:32 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t dim)
{
	size_t	h;
	void	*d;

	while (num == 0 || dim == 0)
	{
		num = 1;
		dim = 1;
	}
	h = dim * num;
	d = malloc(h);
	if (d == 0)
		return (0);
	else
		ft_bzero(d, h);
	return (d);
}
