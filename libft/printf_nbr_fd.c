/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:36:35 by noudrib           #+#    #+#             */
/*   Updated: 2024/04/14 18:14:30 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_nbr_fd(long nbr, int fd)
{
	int	printed_chars;
	int	i;

	printed_chars = 0;
	if (nbr < 0)
	{
		if (printf_char_fd('-', fd) == -1)
			return (-1);
		nbr *= -1;
		printed_chars++;
	}
	if (nbr / 10 == 0)
	{
		if (printf_char_fd(nbr + 48, fd) == -1)
			return (-1);
		return (printed_chars + 1);
	}
	else
	{
		i = printf_nbr_fd(nbr / 10, fd);
		if (i == -1 || printf_char_fd(nbr % 10 + 48, fd) == -1)
			return (-1);
		printed_chars += i + 1;
	}
	return (printed_chars);
}

// static int	str_fill(char *str, int i, int n, int fd)
// {
// 	int	j;

// 	j = 0;
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		j = 1;
// 		n *= -1;
// 	}
// 	else if (n >= 0)
// 		i--;
// 	while (j <= i)
// 	{
// 		str[i--] = n % 10 + 48;
// 		n /= 10;
// 	}
// 	if (ft_putstr_fd(str, fd) < 0)
// 	{
// 		free (str);
// 		return (-1);
// 	}
// 	free (str);
// 	return (1);
// }

// int	ft_putnbr_fd(int n, int fd)
// {
// 	int		i;
// 	int		a;
// 	char	*str;

// 	if (n == -2147483648)
// 		return (ft_putstr_fd("-2147483648", 1));
// 	i = 1;
// 	a = n;
// 	while (a / 10 != 0 && i++)
// 		a /= 10;
// 	if (n < 0)
// 		str = (char *) ft_calloc(i + 2, sizeof(char));
// 	else
// 		str = (char *) ft_calloc(i + 1, sizeof(char));
// 	if (str == NULL)
// 		return (-1);
// 	if (str_fill(str, i, n, fd) < 0)
// 		return (-1);
// 	if (n < 0)
// 		return (i + 1);
// 	return (i);
// }