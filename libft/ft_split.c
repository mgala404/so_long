/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:23:29 by mgala             #+#    #+#             */
/*   Updated: 2022/10/31 14:59:08 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	sn;

	i = 0;
	sn = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			sn++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] != '\0')
			i++;
	}
	return (sn);
}

static size_t	ft_strlenlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ns;
	int		j;
	char	**str;

	j = 0;
	i = 0;
	ns = ft_count (s, c);
	str = malloc (sizeof(char *) * (ns + 1));
	while (ns--)
	{
		while (s[i] != 0)
		{
			if (s[i] != c)
			{
				str[j] = ft_substr(s, i, ft_strlenlen(&s[i], c));
				i = i + ft_strlenlen(&s[i], c);
				break ;
			}
			i++;
		}
		j++;
	}
	str[j] = 0;
	return (str);
}
