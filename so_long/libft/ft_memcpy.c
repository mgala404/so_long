/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:36:38 by mgala             #+#    #+#             */
/*   Updated: 2022/11/02 18:21:07 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		a;
	char		*k;
	const char	*z;

	a = 0;
	k = (char *)dest;
	z = (char *)src;
	while (a < n)
	{
		k[a] = z[a];
		a++;
	}
	return (dest);
}
