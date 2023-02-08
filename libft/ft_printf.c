/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:19:36 by llombard          #+#    #+#             */
/*   Updated: 2022/11/16 16:43:55 by llombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	prova(va_list mod, char format)
{
	int	post;

	post = 0;
	if (format == 'c')
		post += ft_printfputchar(va_arg(mod, int));
	if (format == 's')
		post += ft_printfstring(va_arg(mod, char *));
	if (format == 'p')
		post += ft_printfpointer(va_arg(mod, unsigned long));
	if (format == 'd' || format == 'i')
		post += ft_printfputnbr(va_arg(mod, int));
	if (format == 'u')
		post += ft_printfunsi(va_arg(mod, unsigned int));
	if (format == 'x' || format == 'X')
		post += ft_printfnbrexa(va_arg(mod, unsigned int), format);
	if (format == '%')
	{
		write (1, "%", 1);
		post = 1;
	}
	return (post);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	mod;

	i = 0;
	res = 0;
	va_start(mod, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			res += prova(mod, str[i + 1]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			res++;
		}
		i++;
	}
	va_end(mod);
	return (res);
}
