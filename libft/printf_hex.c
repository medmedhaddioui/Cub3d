/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:46:38 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/14 17:16:30 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_fill(char *str, int i, unsigned int n, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	while (i)
	{
		str[--i] = hex[n % 16];
		n /= 16;
	}
}

int	printf_hex(unsigned int n, char c)
{
	int					i;
	unsigned int		a;
	char				*str;

	i = 1;
	a = n;
	while (a / 16 != 0 && i++)
		a /= 16;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	str[i] = '\0';
	str_fill(str, i, n, c);
	if (printf_str_fd(str, 1) < 0)
	{
		free (str);
		return (-1);
	}
	free (str);
	return (i);
}
