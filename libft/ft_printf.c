/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:36:42 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/14 18:46:00 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(char c, va_list ap)
{
	if (c == 'c')
		return (printf_char_fd((char)va_arg(ap, int), 1));
	else if (c == 's')
		return (printf_str_fd(va_arg(ap, char *), 1));
	else if (c == 'p')
		return (printf_addr_hex((unsigned long)va_arg(ap, void *)));
	else if ((c == 'd' || c == 'i'))
		return (printf_nbr_fd(va_arg(ap, int), 1));
	else if (c == '%')
		return (printf_char_fd('%', 1));
	else if (c == 'u')
		return (printf_unsi_nbr(va_arg(ap, unsigned int), 1));
	else if (c == 'x')
		return (printf_hex(va_arg(ap, unsigned int), 'x'));
	else if (c == 'X')
		return (printf_hex(va_arg(ap, unsigned int), 'X'));
	else if (c != 0)
		return (printf_char_fd(c, 1));
	return (0);
}

static int	ft_help(const char *s, va_list ap)
{
	int	i;
	int	l;
	int	printed_chars;

	i = 0;
	printed_chars = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			if (++printed_chars && printf_char_fd(s[i], 1) < 0)
				return (-1);
		}
		else if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (0);
			l = print_arg(s[++i], ap);
			if (l < 0)
				return (-1);
			printed_chars += l;
		}
		i++;
	}
	return (printed_chars);
}

int	ft_printf(const char *s, ...)
{
	int		printed_chars;
	va_list	ap;

	va_start(ap, s);
	printed_chars = ft_help(s, ap);
	if (printed_chars < 0)
		return (-1);
	va_end(ap);
	return (printed_chars);
}
