/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsi_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:37:09 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/14 18:24:26 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	str_fill(char *str, int i, unsigned int n)
{
	while (i)
	{
		str[--i] = n % 10 + 48;
		n /= 10;
	}
}

int	printf_unsi_nbr(unsigned int n, int fd)
{
	int				i;
	unsigned int	a;
	char			*str;

	i = 1;
	a = n;
	while (a / 10 != 0 && i++)
		a /= 10;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	str[i] = '\0';
	str_fill(str, i, n);
	if (printf_str_fd(str, fd) < 0)
	{
		free (str);
		return (-1);
	}
	free (str);
	return (i);
}
