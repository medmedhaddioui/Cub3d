/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_addr_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:21:40 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/14 17:52:33 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_fill(char *str, int i, unsigned long n)
{
	char	*hex;

	hex = "0123456789abcdef";
	while (i)
	{
		str[--i] = hex[n % 16];
		n /= 16;
	}
}

int	printf_addr_hex(unsigned long n)
{
	int					i;
	unsigned long		a;
	char				*str;

	i = 1;
	a = n;
	while (a / 16 != 0 && i++)
		a /= 16;
	if (printf_str_fd("0x", 1) == -1)
		return (-1);
	str = (char *) malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	str[i] = '\0';
	str_fill(str, i, n);
	if (printf_str_fd(str, 1) < 0)
	{
		free (str);
		return (-1);
	}
	free (str);
	return (i + 2);
}
