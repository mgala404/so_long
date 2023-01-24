/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:14 by mgala             #+#    #+#             */
/*   Updated: 2022/11/03 15:31:55 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1l;
	int		s2l;
	char	*dest;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	dest = malloc(sizeof(char) * (s1l + s2l + 1));
	ft_strlcpy(dest, s1, s1l + 1);
	ft_strlcat(dest, s2, s1l + s2l + 1);
	return (dest);
}
