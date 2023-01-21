/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:00:42 by mgala             #+#    #+#             */
/*   Updated: 2022/10/24 17:08:32 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (src[y] != '\0')
	{
		y++;
	}
	if (size != 0)
	{
		while (src[x] != '\0' && x < (size -1))
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	return (y);
}
