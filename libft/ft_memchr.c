/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:06 by mgala             #+#    #+#             */
/*   Updated: 2022/11/02 17:41:49 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char		*x;
	size_t		y;

	x = (char *) str;
	y = 0;
	while (y < n)
	{
		if ((unsigned char)x[y] == (unsigned char)c)
			return ((char *)str + y);
		y++;
	}
	return (0);
}
