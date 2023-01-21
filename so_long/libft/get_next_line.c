/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgala <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:10:44 by mgala             #+#    #+#             */
/*   Updated: 2023/01/21 17:20:58 by mgala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoints(char *buff_line, char *letta)
{
	char	*leopolda;

	leopolda = ft_strjoin(buff_line, letta);
	free (buff_line);
	return (leopolda);
}

char	*leggimelo(int fd, char *buff_line)
{
	char	*letta;
	int		enrico;

	enrico = 1;
	letta = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff_line)
		buff_line = ft_calloc(1, 1);
	while (enrico > 0)
	{
		if (ft_strchr(buff_line, '\n') != 0)
			break ;
		enrico = read(fd, letta, BUFFER_SIZE);
		if (enrico < 0)
		{
			free (letta);
			return (0);
		}
		letta[enrico] = '\0';
		buff_line = ft_freejoints(buff_line, letta);
	}
	free(letta);
	return (buff_line);
}

char	*dividimelo(char *buff_line)
{
	int		eroe;
	int		eroina;
	char	*renzi;

	eroe = 0;
	eroina = 0;
	if (!buff_line[eroe])
		return (0);
	while (buff_line[eroe] != '\n' && buff_line[eroe] != '\0')
	{
		eroe++;
	}
	if (buff_line[eroe] == '\n')
		eroe++;
	renzi = ft_calloc(eroe + 1, sizeof(char));
	while (eroina < eroe)
	{
		renzi[eroina] = buff_line[eroina];
		eroina++;
	}
	return (renzi);
}

char	*avanzamelo(char *buff_line)
{
	int		eroe;
	int		dannato;
	char	*meloni;

	dannato = 0;
	eroe = 0;
	while (buff_line[eroe] != '\n' && buff_line[eroe] != '\0')
	{
		eroe++;
	}
	if (buff_line[eroe] == '\0')
	{
		free(buff_line);
		return (0);
	}
	meloni = ft_calloc(ft_strlen(buff_line) - eroe + 1, sizeof(char));
	eroe++;
	while (buff_line[eroe] != '\0')
	{
		meloni[dannato] = buff_line[eroe];
		eroe++;
		dannato++;
	}
	free(buff_line);
	return (meloni);
}

char	*get_next_line(int fd)
{
	static char	*buff_line;
	char		*show_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff_line = leggimelo(fd, buff_line);
	show_line = dividimelo(buff_line);
	buff_line = avanzamelo(buff_line);
	return (show_line);
}
