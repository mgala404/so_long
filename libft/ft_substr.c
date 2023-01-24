/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:56:25 by mgala             #+#    #+#             */
/*   Updated: 2022/11/03 17:12:12 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t	i;
	size_t	j;
	char	*pt;

	i = 0;
	j = 0;
	pt = malloc(sizeof(*s) * (len + 1));
	if (!pt)
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			pt[j] = s[i];
			j++;
		}
		i++;
	}
	pt[j] = 0;
	return (pt);
}
